//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// mtimes.h
//
// Code generation for function 'mtimes'
//

#pragma once

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include "emlrt.h"
#include "mex.h"
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

// Function Declarations
namespace coder {
namespace internal {
namespace blas {
void mtimes(const real_T A_data[], const int32_T A_size[2],
            const ::coder::array<real_T, 2U> &B, real_T C_data[],
            int32_T *C_size);

}
} // namespace internal
} // namespace coder

// End of code generation (mtimes.h)
