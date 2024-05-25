#pragma once

#include <chk/core/types.h>
#include <chk/core/vec/v2.h>

#undef CHK_DEFINE_RECT
#define CHK_DEFINE_RECT(Type, Suffix)                                          \
    typedef union Rect##Suffix {                                               \
        Type data[4];                                                          \
        struct {                                                               \
            Type x, y, w, h;                                                   \
        };                                                                     \
        struct {                                                               \
            V2##Suffix pos;                                                    \
            V2##Suffix size;                                                   \
        };                                                                     \
    } Rect##Suffix;                                                            \
                                                                               \
    Type       chk_rect##Suffix##_center_x(Rect##Suffix r);                    \
    Type       chk_rect##Suffix##_center_y(Rect##Suffix r);                    \
    V2##Suffix chk_rect##Suffix##_center(Rect##Suffix r);                      \
    V2##Suffix chk_rect##Suffix##_center_u(Rect##Suffix r);                    \
    V2##Suffix chk_rect##Suffix##_center_d(Rect##Suffix r);                    \
    V2##Suffix chk_rect##Suffix##_center_l(Rect##Suffix r);                    \
    V2##Suffix chk_rect##Suffix##_center_r(Rect##Suffix r);

CHK_DEFINE_RECT(R32, _f)
CHK_DEFINE_RECT(S32, _s)
CHK_DEFINE_RECT(U32, _u)

typedef Rect_f Rect;

#undef CHK_DEFINE_RECT
