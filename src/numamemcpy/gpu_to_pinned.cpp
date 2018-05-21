#include <assert.h>
#include <iostream>
#include <stdio.h>
#include <string.h>

#include <cuda_runtime.h>
#include <numa.h>

#include "init/init.hpp"
#include "utils/utils.hpp"

#include "numamemcpy/args.hpp"

#define NAME "NUMA/Memcpy/GPUToPinned"

static void NUMA_Memcpy_GPUToPinned(benchmark::State &state) {

  if (!has_cuda) {
    state.SkipWithError(NAME " no CUDA device found");
    return;
  }

  if (PRINT_IF_ERROR(cudaDeviceReset())) {
    state.SkipWithError(NAME " failed to reset device");
    return;
  }

  if (!has_numa) {
    state.SkipWithError(NAME " NUMA not available");
    return;
  }

  const int numa_id = state.range(1);
  const int cuda_id = state.range(2);

  const auto bytes = 1ULL << static_cast<size_t>(state.range(0));
  char *src        = nullptr;

  char *dst = nullptr;
  if (PRINT_IF_ERROR(cudaHostAlloc(&dst, bytes, cudaHostAllocDefault))) {
    state.SkipWithError(NAME " failed to perform pinned cudaHostAlloc");
    return;
  }
  defer(cudaFreeHost(dst));

  numa_bind_node(numa_id);

  if (PRINT_IF_ERROR(cudaSetDevice(cuda_id))) {
    state.SkipWithError(NAME " failed to set CUDA device");
    return;
  }

  if (PRINT_IF_ERROR(cudaMalloc(&src, bytes))) {
    state.SkipWithError(NAME " failed to perform cudaMalloc");
    return;
  }
  defer(cudaFree(src));

  if (PRINT_IF_ERROR(cudaMemset(src, 0, bytes))) {
    state.SkipWithError(NAME " failed to perform cudaMemset");
    return;
  }

  cudaEvent_t start, stop;
  PRINT_IF_ERROR(cudaEventCreate(&start));
  PRINT_IF_ERROR(cudaEventCreate(&stop));

  for (auto _ : state) {
    cudaEventRecord(start, NULL);

    const auto cuda_err = cudaMemcpy(dst, src, bytes, cudaMemcpyDeviceToHost);


    cudaEventRecord(stop, NULL);
    cudaEventSynchronize(stop);

    if (PRINT_IF_ERROR(cuda_err) != cudaSuccess) {
      state.SkipWithError(NAME " failed to perform memcpy");
      break;
    }

    float msecTotal = 0.0f;
    if (PRINT_IF_ERROR(cudaEventElapsedTime(&msecTotal, start, stop))) {
      state.SkipWithError(NAME " failed to get elapsed time");
      break;
    }
    state.SetIterationTime(msecTotal / 1000);

  }
  state.SetBytesProcessed(int64_t(state.iterations()) * int64_t(bytes));
  state.counters.insert({{"bytes", bytes}});

  // reset to run on any node
  numa_bind_node(-1);
}

BENCHMARK(NUMA_Memcpy_GPUToPinned)->Apply(ArgsCountNumaGpu)->UseManualTime();
