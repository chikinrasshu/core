#pragma once

#include <chk/core/types.h>

#define CHK_DEFINE_V2(Type, Suffix)                                            \
    typedef union V2##Suffix {                                                 \
        Type data[2];                                                          \
        struct {                                                               \
            Type x, y;                                                         \
        };                                                                     \
        struct {                                                               \
            Type u, v;                                                         \
        };                                                                     \
        struct {                                                               \
            Type s, t;                                                         \
        };                                                                     \
        struct {                                                               \
            Type w, h;                                                         \
        };                                                                     \
    } V2##Suffix;

#define CHK_DEFINE_V3(Type, Suffix)                                            \
    typedef union V3##Suffix {                                                 \
        Type data[3];                                                          \
        struct {                                                               \
            Type x, y, z;                                                      \
        };                                                                     \
        struct {                                                               \
            V2##Suffix xy;                                                     \
            Type       _unused_1;                                              \
        };                                                                     \
    } V3##Suffix;

#define CHK_DEFINE_V4(Type, Suffix)                                            \
    typedef union V4##Suffix {                                                 \
        Type data[4];                                                          \
        struct {                                                               \
            Type x, y, z, w;                                                   \
        };                                                                     \
        struct {                                                               \
            V2##Suffix xy;                                                     \
            Type       _unused_1;                                              \
            Type       _unused_2;                                              \
        };                                                                     \
        struct {                                                               \
            V3##Suffix xyz;                                                    \
            Type       _unused_3;                                              \
        };                                                                     \
    } V4##Suffix;

CHK_DEFINE_V2(R32, _f)
CHK_DEFINE_V2(S32, _s)
CHK_DEFINE_V2(U32, _u)

CHK_DEFINE_V3(R32, _f)
CHK_DEFINE_V3(S32, _s)
CHK_DEFINE_V3(U32, _u)

CHK_DEFINE_V4(R32, _f)
CHK_DEFINE_V4(S32, _s)
CHK_DEFINE_V4(U32, _u)

typedef V2_f V2;
typedef V3_f V3;
typedef V4_f V4;

#undef CHK_DEFINE_V2
#undef CHK_DEFINE_V3
#undef CHK_DEFINE_V4
