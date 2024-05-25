#pragma once

#include <chk/core/types.h>

typedef union RGB {
    R32 data[3];
    struct {
        R32 r, g, b;
    };
} RGB;

bool chk_rgb_pack(RGB* in, U32* out);
bool chk_rgb_unpack(U32* in, RGB* out);

typedef union RGBA {
    R32 data[4];
    struct {
        R32 r, g, b, a;
    };
    struct {
        RGB rgb;
        R32 _unused_a;
    };
} RGBA;

bool chk_rgba_pack(RGBA* in, U32* out);
bool chk_rgba_unpack(U32* in, RGBA* out);
