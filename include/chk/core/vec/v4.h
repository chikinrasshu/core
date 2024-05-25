#pragma once

#include <chk/core/vec/fwd.h>

#define CHK_V4_DEFINE(Type, Suffix)                                            \
    V4##Suffix chk_v4##Suffix##_add(V4##Suffix a, V4##Suffix b);               \
    V4##Suffix chk_v4##Suffix##_sub(V4##Suffix a, V4##Suffix b);               \
    V4##Suffix chk_v4##Suffix##_mul(V4##Suffix a, Type b);                     \
    V4##Suffix chk_v4##Suffix##_div(V4##Suffix a, Type b);                     \
    Type       chk_v4##Suffix##_dot(V4##Suffix a, V4##Suffix b);               \
    Type       chk_v4##Suffix##_dist_sq(V4##Suffix a, V4##Suffix b);           \
    Type       chk_v4##Suffix##_dist(V4##Suffix a, V4##Suffix b);              \
    Type       chk_v4##Suffix##_len_sq(V4##Suffix a);                          \
    Type       chk_v4##Suffix##_len(V4##Suffix a);

CHK_V4_DEFINE(R32, _f)
CHK_V4_DEFINE(S32, _s)
CHK_V4_DEFINE(U32, _u)

#undef CHK_V4_DEFINE
