#pragma once

#include <chk/core/vec/fwd.h>

#define CHK_V3_DEFINE(Type, Suffix)                                            \
    V3##Suffix chk_v3##Suffix##_add(V3##Suffix a, V3##Suffix b);               \
    V3##Suffix chk_v3##Suffix##_sub(V3##Suffix a, V3##Suffix b);               \
    V3##Suffix chk_v3##Suffix##_mul(V3##Suffix a, Type b);                     \
    V3##Suffix chk_v3##Suffix##_div(V3##Suffix a, Type b);                     \
    V3##Suffix chk_v3##Suffix##_cross(V3##Suffix a, V3##Suffix b);             \
    Type       chk_v3##Suffix##_dot(V3##Suffix a, V3##Suffix b);               \
    Type       chk_v3##Suffix##_dist_sq(V3##Suffix a, V3##Suffix b);           \
    Type       chk_v3##Suffix##_dist(V3##Suffix a, V3##Suffix b);              \
    Type       chk_v3##Suffix##_len_sq(V3##Suffix a);                          \
    Type       chk_v3##Suffix##_len(V3##Suffix a);

CHK_V3_DEFINE(R32, f)
CHK_V3_DEFINE(S32, s)
CHK_V3_DEFINE(U32, u)

#undef CHK_V3_DEFINE
