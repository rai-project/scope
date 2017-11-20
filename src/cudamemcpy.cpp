#include <assert.h>
#include <benchmark/benchmark.h>
#include <cuda_runtime.h>
#include <iostream>
#include <stdio.h>

static void CUDAMemcpyToGPU(benchmark::State &state) {
  const auto bytes = 1ULL << static_cast<size_t>(state.range(0));
  char *src = new char[bytes];
  char *dst = nullptr;
  const auto err = cudaMalloc(&dst, bytes);
  if (err != cudaSuccess) {
    state.SkipWithError("failed to perform cudaMemcpy");
    return;
  }
  for (auto _ : state) {
    const auto err = cudaMemcpy(dst, src, bytes, cudaMemcpyHostToDevice);
    if (err != cudaSuccess) {
      state.SkipWithError("failed to perform cudaMemcpy");
      break;
    }
  }
  state.SetBytesProcessed(int64_t(state.iterations()) * int64_t(bytes));
  state.counters.insert({{"bytes", bytes}});
  if (dst) {
    cudaFree(dst);
  }
  delete[] src;
}
BENCHMARK(CUDAMemcpyToGPU)->DenseRange(1, 32, 1);
