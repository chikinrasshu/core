#include <chk/core/vec/v3.h>

#include <math.h>

#define CHK_V3_DEFINE(Type, Suffix)                                            \
    V3##Suffix chk_v3##Suffix##_add(V3##Suffix a, V3##Suffix b) {              \
        V3##Suffix result = {a.x + b.x, a.y + b.y, a.z + b.z};                 \
        return result;                                                         \
    }                                                                          \
                                                                               \
    V3##Suffix chk_v3##Suffix##_sub(V3##Suffix a, V3##Suffix b) {              \
        V3##Suffix result = {a.x - b.x, a.y - b.y, a.z - b.z};                 \
        return result;                                                         \
    }                                                                          \
                                                                               \
    V3##Suffix chk_v3##Suffix##_mul(V3##Suffix a, Type b) {                    \
        V3##Suffix result = {a.x * b, a.y * b, a.z * b};                       \
        return result;                                                         \
    }                                                                          \
                                                                               \
    V3##Suffix chk_v3##Suffix##_div(V3##Suffix a, Type b) {                    \
        V3##Suffix result = {a.x / b, a.y / b, a.z / b};                       \
        return result;                                                         \
    }                                                                          \
                                                                               \
    V3##Suffix chk_v3##Suffix##_cross(V3##Suffix a, V3##Suffix b) {            \
        Type       rx     = a.y * b.z - a.z * b.y;                             \
        Type       ry     = a.z * b.x - a.x * b.z;                             \
        Type       rz     = a.x * b.y - a.y * b.x;                             \
        V3##Suffix result = {rx, ry, rz};                                      \
        return result;                                                         \
    }                                                                          \
                                                                               \
    Type chk_v3##Suffix##_dot(V3##Suffix a, V3##Suffix b) {                    \
        Type result = a.x * b.x + a.y * b.y + a.z * b.z;                       \
        return result;                                                         \
    }                                                                          \
                                                                               \
    Type chk_v3##Suffix##_dist_sq(V3##Suffix a, V3##Suffix b) {                \
        Type dx = b.x - a.x, dy = b.y - a.y, dz = b.z - a.z;                   \
        Type result = dx * dx + dy * dy + dz * dz;                             \
        return result;                                                         \
    }                                                                          \
                                                                               \
    Type chk_v3##Suffix##_dist(V3##Suffix a, V3##Suffix b) {                   \
        Type result = sqrtf(chk_v3##Suffix##_dist_sq(a, b));                   \
        return result;                                                         \
    }                                                                          \
                                                                               \
    Type chk_v3##Suffix##_len_sq(V3##Suffix a) {                               \
        Type result = chk_v3##Suffix##_dot(a, a);                              \
        return result;                                                         \
    }                                                                          \
                                                                               \
    Type chk_v3##Suffix##_len(V3##Suffix a) {                                  \
        Type result = sqrtf(chk_v3##Suffix##_len_sq(a));                       \
        return result;                                                         \
    }

CHK_V3_DEFINE(R32, _f)
CHK_V3_DEFINE(S32, _s)
CHK_V3_DEFINE(U32, _u)

#undef CHK_V3_DEFINE
