#pragma once

#define leaf_Result_Typedef(T, E) leaf_Result_Typedef_##T##_##E

#define leaf_Result_pre(T, E)                                                  \
  typedef struct {                                                             \
    union {                                                                    \
      T ok;                                                                    \
      E err;                                                                   \
    } value;                                                                   \
    bool isErr;                                                                \
  } leaf_Result_Typedef(T, E);

#define leaf_Result_t(T, E) leaf_Result_Typedef(T, E)

#define leaf_Result_IsErr(result) (result.isErr)

#define leaf_Result_getValue(result) (result.value.ok)

#define leaf_Result_getError(result) (result.value.err)

#define leaf_Result_SaveError(T, E, Err)                                       \
  ((leaf_Result_Typedef(T, E)){.value.err = Err, .isErr = true})

#define leaf_Result_SaveOk(T, E, Ok)                                           \
  ((leaf_Result_Typedef(T, E)){.value.ok = Ok, .isErr = false})

#define leaf_Result_ReturnError(T, E, Err)                                     \
  return leaf_Result_SaveError(T, E, Err);

#define leaf_Result_ReturnOk(T, E, Ok) return leaf_Result_SaveOk(T, E, Ok);
