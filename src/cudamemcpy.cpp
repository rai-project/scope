#include <stdio.h>
#include <assert.h>
#include <cuda.h>

// Convenience function for checking CUDA runtime API results
// can be wrapped around any runtime API call. No-op in release builds.
inline
cudaError_t checkCuda(cudaError_t result)
{
#if defined(DEBUG) || defined(_DEBUG)
  if (result != cudaSuccess) {
    fprintf(stderr, "CUDA Runtime Error: %s\n", cudaGetErrorString(result));
    assert(result == cudaSuccess);
  }
#endif
  return result;
}

static void CUDAMEMCPYTEST() {
  unsigned int nElements = 4*1024*1024;
  const unsigned int bytes = nElements * sizeof(float);

  // host arrays
  float *h_aPageable, *h_bPageable;
  float *h_a, *h_bPinned;X

  // device array
  float *d_a;

  // allocate and initialize
  h_aPageable = (float*)malloc(bytes);                    // host pageable
  h_bPageable = (float*)malloc(bytes);                    // host pageable
  checkCuda( cudaMalloc((void**)&h_a, bytes) ); // host pinned
  checkCuda( cudaMallocHost((void**)&h_bPinned, bytes) ); // host pinned
  checkCuda( cudaMalloc((void**)&d_a, bytes) );           // device

  checkCuda( cudaMemcpy(d_a, h_a, bytes, cudaMemcpyHostToDevice) );
  checkCuda( cudaMemcpy(d_a, h_bPinned, bytes, cudaMemcpyHostToDevice) );
  checkCuda( cudaMemcpy(d_a, h_a, bytes, cudaMemcpyDeviceToHost) );
}
