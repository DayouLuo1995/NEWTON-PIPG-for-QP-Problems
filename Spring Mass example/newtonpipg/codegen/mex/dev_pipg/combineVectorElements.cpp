//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// combineVectorElements.cpp
//
// Code generation for function 'combineVectorElements'
//

// Include files
#include "combineVectorElements.h"
#include "dev_pipg_data.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Variable Definitions
static emlrtRSInfo xb_emlrtRSI{
    138,                     // lineNo
    "combineVectorElements", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2022b\\toolbox\\eml\\lib\\matlab\\datafun\\private\\combin"
    "eVectorElements.m" // pathName
};

static emlrtRSInfo yb_emlrtRSI{
    198,                // lineNo
    "colMajorFlatIter", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2022b\\toolbox\\eml\\lib\\matlab\\datafun\\private\\combin"
    "eVectorElements.m" // pathName
};

// Function Definitions
namespace coder {
int32_T combineVectorElements(const emlrtStack *sp,
                              const ::coder::array<boolean_T, 1U> &x)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  int32_T vlen;
  int32_T y;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  vlen = x.size(0);
  if (x.size(0) == 0) {
    y = 0;
  } else {
    st.site = &xb_emlrtRSI;
    y = x[0];
    b_st.site = &yb_emlrtRSI;
    if (x.size(0) > 2147483646) {
      c_st.site = &w_emlrtRSI;
      check_forloop_overflow_error(&c_st);
    }
    for (int32_T k{2}; k <= vlen; k++) {
      y += x[k - 1];
    }
  }
  return y;
}

} // namespace coder

// End of code generation (combineVectorElements.cpp)
