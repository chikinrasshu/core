#include <chk/core/vec/v4.h>

#include <math.h>

#define CHK_V4_DEFINE(Type, Suffix)                                            \
    V4##Suffix chk_v4##Suffix##_add(V4##Suffix a, V4##Suffix b) {              \
        V4##Suffix result = {a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w};      \
        return result;                                                         \
    }                                                                          \
                                                                               \
    V4##Suffix chk_v4##Suffix##_sub(V4##Suffix a, V4##Suffix b) {              \
        V4##Suffix result = {a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w};      \
        return result;                                                         \
    }                                                                          \
                                                                               \
    V4##Suffix chk_v4##Suffix##_mul(V4##Suffix a, Type b) {                    \
        V4##Suffix result = {a.x * b, a.y * b, a.z * b, a.w * b};              \
        return result;                                                         \
    }                                                                          \
                                                                               \
    V4##Suffix chk_v4##Suffix##_div(V4##Suffix a, Type b) {                    \
        V4##Suffix result = {a.x / b, a.y / b, a.z / b, a.w / b};              \
        return result;                                                         \
    }                                                                          \
                                                                               \
    Type chk_v4##Suffix##_dot(V4##Suffix a, V4##Suffix b) {                    \
        Type result = a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w;           \
        return result;                                                         \
    }                                                                          \
                                                                               \
    Type chk_v4##Suffix##_dist_sq(V4##Suffix a, V4##Suffix b) {                \
        Type dx = b.x - a.x, dy = b.y - a.y, dz = b.z - a.z, dw = b.w - a.w;   \
        Type result = dx * dx + dy * dy + dz * dz + dw * dw;                   \
        return result;                                                         \
    }                                                                          \
                                                                               \
    Type chk_v4##Suffix##_dist(V4##Suffix a, V4##Suffix b) {                   \
        Type result = sqrtf(chk_v4##Suffix##_dist_sq(a, b));                   \
        return result;                                                         \
    }                                                                          \
                                                                               \
    Type chk_v4##Suffix##_len_sq(V4##Suffix a) {                               \
        Type result = chk_v4##Suffix##_dot(a, a);                              \
        return result;                                                         \
    }                                                                          \
                                                                               \
    Type chk_v4##Suffix##_len(V4##Suffix a) {                                  \
        Type result = sqrtf(chk_v4##Suffix##_len_sq(a));                       \
        return result;                                                         \
    }

CHK_V4_DEFINE(R32, f)
CHK_V4_DEFINE(S32, s)
CHK_V4_DEFINE(U32, u)

#undef CHK_V4_DEFINE
