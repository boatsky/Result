#pragma once

#define leaf_Result(T, E)                                                           \
  struct {                                                                     \
    union {                                                                    \
      T ok;                                                                    \
      E err;                                                                   \
    } value;                                                                   \
    bool isErr;                                                                \
  }

#define leaf_Result_IsErr(result) (result.isErr)

#define leaf_Result_value(result) (result.value.ok)

#define leaf_Result_error(result) (result.value.err)
