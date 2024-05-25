#include <chk/core/vec/v2.h>

#include <math.h>

#define CHK_V2_DEFINE(Type, Suffix)                                            \
    V2##Suffix chk_v2##Suffix##_add(V2##Suffix a, V2##Suffix b) {              \
        V2##Suffix result = {a.x + b.x, a.y + b.y};                            \
        return result;                                                         \
    }                                                                          \
                                                                               \
    V2##Suffix chk_v2##Suffix##_sub(V2##Suffix a, V2##Suffix b) {              \
        V2##Suffix result = {a.x - b.x, a.y - b.y};                            \
        return result;                                                         \
    }                                                                          \
                                                                               \
    V2##Suffix chk_v2##Suffix##_mul(V2##Suffix a, Type b) {                    \
        V2##Suffix result = {a.x * b, a.y * b};                                \
        return result;                                                         \
    }                                                                          \
                                                                               \
    V2##Suffix chk_v2##Suffix##_div(V2##Suffix a, Type b) {                    \
        V2##Suffix result = {a.x / b, a.y / b};                                \
        return result;                                                         \
    }                                                                          \
                                                                               \
    Type chk_v2##Suffix##_dot(V2##Suffix a, V2##Suffix b) {                    \
        Type result = a.x * b.x + a.y * b.y;                                   \
        return result;                                                         \
    }                                                                          \
                                                                               \
    Type chk_v2##Suffix##_dist_sq(V2##Suffix a, V2##Suffix b) {                \
        Type dx = b.x - a.x, dy = b.y - a.y;                                   \
        Type result = dx * dx + dy * dy;                                       \
        return result;                                                         \
    }                                                                          \
                                                                               \
    Type chk_v2##Suffix##_dist(V2##Suffix a, V2##Suffix b) {                   \
        Type result = sqrtf(chk_v2##Suffix##_dist_sq(a, b));                   \
        return result;                                                         \
    }                                                                          \
                                                                               \
    Type chk_v2##Suffix##_len_sq(V2##Suffix a) {                               \
        Type result = chk_v2##Suffix##_dot(a, a);                              \
        return result;                                                         \
    }                                                                          \
                                                                               \
    Type chk_v2##Suffix##_len(V2##Suffix a) {                                  \
        Type result = sqrtf(chk_v2##Suffix##_len_sq(a));                       \
        return result;                                                         \
    }

CHK_V2_DEFINE(R32, _f)
CHK_V2_DEFINE(S32, _s)
CHK_V2_DEFINE(U32, _u)

#undef CHK_V2_DEFINE
