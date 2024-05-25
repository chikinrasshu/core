#pragma once

#include <chk/core/vec/fwd.h>

#define CHK_V2_DEFINE(Type, Suffix)                                            \
    V2##Suffix chk_v2##Suffix##_add(V2##Suffix a, V2##Suffix b);               \
    V2##Suffix chk_v2##Suffix##_sub(V2##Suffix a, V2##Suffix b);               \
    V2##Suffix chk_v2##Suffix##_mul(V2##Suffix a, Type b);                     \
    V2##Suffix chk_v2##Suffix##_div(V2##Suffix a, Type b);                     \
    Type       chk_v2##Suffix##_dot(V2##Suffix a, V2##Suffix b);               \
    Type       chk_v2##Suffix##_dist_sq(V2##Suffix a, V2##Suffix b);           \
    Type       chk_v2##Suffix##_dist(V2##Suffix a, V2##Suffix b);              \
    Type       chk_v2##Suffix##_len_sq(V2##Suffix a);                          \
    Type       chk_v2##Suffix##_len(V2##Suffix a);

CHK_V2_DEFINE(R32, _f)
CHK_V2_DEFINE(S32, _s)
CHK_V2_DEFINE(U32, _u)

#undef CHK_V2_DEFINE
