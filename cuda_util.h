/*************************************************************************
  > File Name   : cuda_util.h
  > Author      : Liu Junhong
  > Mail        : junliu@nvidia.com
  > Created Time: Wednesday, March 11, 2020 AM12:04:38 HKT
 ************************************************************************/

#ifndef _CUDA_UTIL_H
#define _CUDA_UTIL_H

#include <cuda_runtime_api.h>
#include <stdlib.h>

#define CUDA_CHECK(X) \
  do {\
    cudaError_t err = X;\
    if (err != cudaSuccess) {\
      fprintf(stderr, "%s failed, err=%d, %s\n", #X, err, cudaGetErrorName(err));\
      abort();\
    }\
  } while(0)


#define CUDNN_CHECK(X) \
    do { \
        cudnnStatus_t err = X;\
        if (err != CUDNN_STATUS_SUCCESS) { \
            fprintf(stderr, "%s failed, err=%d, %s\n", #X, err, cudnnGetErrorString(err)); \
            abort(); \
        } \
    } while(0)

#define checkKernelErrors() do {                                                                \
    cudaError_t __err = cudaGetLastError();                                                         \
    if (__err != cudaSuccess) {                                                                     \
        fprintf(stderr, "Line %d: failed: %s\n", __LINE__, cudaGetErrorString(__err));  \
        abort();                                                                                    \
    }                                                                                               \
} while(0)

#endif
