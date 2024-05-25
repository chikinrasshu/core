#pragma once

#include <chk/core/types.h>

typedef struct Arena {
    Size  size, used;
    void* data;
} Arena;

bool chk_arena_create(Arena* a, Size size);
bool chk_arena_destroy(Arena* a);

bool chk_arena_reset(Arena* a);
bool chk_arena_push(Arena* a, Size size, void** out);

#define chk_arena_push_struct(arena, Type, out)                                \
    chk_arena_push((arena), sizeof(Type), (out))
#define chk_arena_push_array(arena, Type, count, out)                          \
    chk_arena_push((arena), sizeof(Type) * (count), (out))
