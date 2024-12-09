//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// dev_HZ.cpp
//
// Code generation for function 'dev_HZ'
//

// Include files
#include "dev_HZ.h"
#include "dev_newtonpipg_pcg_data.h"
#include "rt_nonfinite.h"
#include <cstring>

// Variable Definitions
static emlrtRSInfo t_emlrtRSI{
    16,       // lineNo
    "dev_HZ", // fcnName
    "C:\\Users\\HP\\Documents\\MATLAB\\Final version with "
    "PCG\\newtonpipg\\devnewton_code\\dev_HZ.m" // pathName
};

static emlrtRSInfo u_emlrtRSI{
    17,       // lineNo
    "dev_HZ", // fcnName
    "C:\\Users\\HP\\Documents\\MATLAB\\Final version with "
    "PCG\\newtonpipg\\devnewton_code\\dev_HZ.m" // pathName
};

// Function Definitions
void dev_HZ(const emlrtStack *sp, const real_T A[256], const real_T B[128],
            const real_T z[496], real_T out[320])
{
  emlrtStack b_st;
  emlrtStack st;
  real_T b_A[256];
  int32_T i;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  // In this function, we define a simple version of H multiply z.
  // Each row of H is [-A,-B,I]
  // By simple, we mean in the matrix H, both A and B are fixed function.
  // This should be sufficient in estimating the speed for computation.
  // dimension of state and control
  // Z consists of T (x, u) + one x
  std::memset(&out[0], 0, 320U * sizeof(real_T));
  for (i = 0; i < 256; i++) {
    b_A[i] = -A[i];
  }
  for (int32_T b_i{0}; b_i < 20; b_i++) {
    int32_T i1;
    int32_T startindexout;
    int32_T startindexz;
    startindexz = b_i * 24 + 16;
    startindexout = b_i << 4;
    if (startindexz - 15 > startindexz) {
      i = 0;
      i1 = 0;
    } else {
      i = startindexz - 16;
      i1 = startindexz;
    }
    st.site = &t_emlrtRSI;
    b_st.site = &v_emlrtRSI;
    i1 -= i;
    if (i1 != 16) {
      if (i1 == 1) {
        emlrtErrorWithMessageIdR2018a(
            &b_st, &e_emlrtRTEI,
            "Coder:toolbox:mtimes_noDynamicScalarExpansion",
            "Coder:toolbox:mtimes_noDynamicScalarExpansion", 0);
      } else {
        emlrtErrorWithMessageIdR2018a(&b_st, &d_emlrtRTEI, "MATLAB:innerdim",
                                      "MATLAB:innerdim", 0);
      }
    }
    st.site = &u_emlrtRSI;
    for (i1 = 0; i1 < 16; i1++) {
      real_T d;
      real_T d1;
      d = 0.0;
      for (int32_T i2{0}; i2 < 16; i2++) {
        d += b_A[i1 + (i2 << 4)] * z[i + i2];
      }
      d1 = 0.0;
      for (int32_T i2{0}; i2 < 8; i2++) {
        d1 += B[i1 + (i2 << 4)] * z[startindexz + i2];
      }
      out[startindexout + i1] = (d - d1) + z[(startindexz + i1) + 8];
    }
    // we want to avoid computing startindexz+lx+lu manytimes in C. Checked.
    // AB should be written as [A;B]. C fixed this.
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtConstCTX)sp);
    }
  }
}

// End of code generation (dev_HZ.cpp)