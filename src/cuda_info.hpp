#pragma once

#include <cuda_runtime.h>
#include <tuple>

#include "optional/optional.hpp"

#include "flags.hpp"
#include "init.hpp"
#include "utils_cuda.hpp"

namespace utils {
namespace cuda {

// using optional = std::experimental::optional;
// using nullopt = std::experimental::nullopt;

static cudaDeviceProp device_prop;
static float device_giga_bandwidth{0};
static size_t device_free_physmem{0};
static size_t device_total_physmem{0};

static cudaError_t device_init() {
  cudaError_t error = cudaSuccess;
  do {
    int deviceCount;
    if (CUDA_PERROR(error = cudaGetDeviceCount(&deviceCount))) {
      break;
    }

    if (deviceCount == 0) {
      LOG(critical, "No devices supporting CUDA.");
      exit(1);
    }

    cuda_device_id = 0;

    if (cuda_device_id < 0) {
      LOG(critical, "device = {} is not valid.", cuda_device_id);
      exit(1);
    }
    if ((cuda_device_id > deviceCount - 1) || (cuda_device_id < 0)) {
      cuda_device_id = 0;
    }

    if (CUDA_PERROR(error = cudaSetDevice(cuda_device_id))) {
      break;
    }

    if (CUDA_PERROR(error = cudaMemGetInfo(&device_free_physmem,
                                           &device_total_physmem))) {
      break;
    }

    if (CUDA_PERROR(
            error = cudaGetDeviceProperties(&device_prop, cuda_device_id))) {
      break;
    }

    if (device_prop.major < 1) {
      LOG(critical, "Device does not support CUDA.");
      exit(1);
    }

    device_giga_bandwidth = float(device_prop.memoryBusWidth) *
                            device_prop.memoryClockRate * 2 / 8 / 1000 / 1000;
  } while (0);
  return error;
}

static std::experimental::optional<std::tuple<size_t, size_t>> mem_info() {
  cudaError_t error = cudaSuccess;
  size_t device_free_physmem, device_total_physmem;

  CUDA_PERROR(error =
                  cudaMemGetInfo(&device_free_physmem, &device_total_physmem));

  if (error) {
    return std::experimental::nullopt;
  }
  return std::make_tuple(device_free_physmem, device_total_physmem);
}

} // namespace cuda
} // namespace utils