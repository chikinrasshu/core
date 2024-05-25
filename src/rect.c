#include <chk/core/rect.h>

#undef CHK_DEFINE_RECT
#define CHK_DEFINE_RECT(Type, Suffix)                                          \
    Type chk_rect##Suffix##_center_x(Rect##Suffix r) {                         \
        Type result = (r.x + r.w) / 2;                                         \
        return result;                                                         \
    }                                                                          \
                                                                               \
    Type chk_rect##Suffix##_center_y(Rect##Suffix r) {                         \
        Type result = (r.y + r.h) / 2;                                         \
        return result;                                                         \
    }                                                                          \
                                                                               \
    V2##Suffix chk_rect##Suffix##_center(Rect##Suffix r) {                     \
        V2##Suffix result = {};                                                \
        return result;                                                         \
    }                                                                          \
                                                                               \
    V2##Suffix chk_rect##Suffix##_center_u(Rect##Suffix r) {                   \
        V2##Suffix result;                                                     \
        return result;                                                         \
    }                                                                          \
                                                                               \
    V2##Suffix chk_rect##Suffix##_center_d(Rect##Suffix r) {                   \
        V2##Suffix result;                                                     \
        return result;                                                         \
    }                                                                          \
                                                                               \
    V2##Suffix chk_rect##Suffix##_center_l(Rect##Suffix r) {                   \
        V2##Suffix result;                                                     \
        return result;                                                         \
    }                                                                          \
                                                                               \
    V2##Suffix chk_rect##Suffix##_center_r(Rect##Suffix r) {                   \
        V2##Suffix result;                                                     \
        return result;                                                         \
    }

CHK_DEFINE_RECT(R32, _f)
CHK_DEFINE_RECT(S32, _s)
CHK_DEFINE_RECT(U32, _u)

#undef CHK_DEFINE_RECT
