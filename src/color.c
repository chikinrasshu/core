#include <chk/core/color.h>

/******************************************************************************/
/* RGB impl                                                                   */
/******************************************************************************/

bool chk_rgb_pack(RGB* in, U32* out) {
    if (!in) { return false; }
    if (!out) { return false; }

    *out = 0;
    *out |= (U8)(in->r * 255.5f) << 16;
    *out |= (U8)(in->g * 255.5f) << 8;
    *out |= (U8)(in->b * 255.5f) << 0;

    return true;
}

bool chk_rgb_unpack(U32* in, RGB* out) {
    if (!in) { return false; }
    if (!out) { return false; }

    out->r = (R32)((*in & 0x00FF0000) >> 16) / 255.0f;
    out->g = (R32)((*in & 0x0000FF00) >> 8) / 255.0f;
    out->b = (R32)((*in & 0x000000FF) >> 0) / 255.0f;

    return true;
}

/******************************************************************************/
/* RGBA impl                                                                  */
/******************************************************************************/

bool chk_rgba_pack(RGBA* in, U32* out) {
    if (!in) { return false; }
    if (!out) { return false; }

    U32 result = 0;
    if (!chk_rgb_pack(&in->rgb, out)) { return false; }
    result |= (U8)(in->a * 255.5f) << 24;

    return true;
}

bool chk_rgba_unpack(U32* in, RGBA* out) {
    if (!in) { return false; }
    if (!out) { return false; }

    if (!chk_rgb_unpack(in, &out->rgb)) { return false; }
    out->a = (R32)((*in & 0xFF000000) >> 24) / 255.0f;

    return true;
}
