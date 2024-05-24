#include <chk/core/arena.h>
#include <chk/core/mem.h>

bool chk_arena_create(Arena* a, Size size) {
    if (!a) { return false; }
    if (!size) { return false; }

    if (a->data) {
        if (!chk_arena_destroy(a)) { return false; }
    }

    a->data = chk_allocate(size);
    if (!a->data) { return false; }

    a->size = size;
    a->used = 0;

    return true;
}

bool chk_arena_destroy(Arena* a) {
    if (!a) { return false; }

    if (!chk_arena_reset(a)) { return false; }

    chk_free(a->data);
    a->data = NULL;

    return true;
}

bool chk_arena_reset(Arena* a) {
    if (!a) { return false; }

    a->used = 0;

    return true;
}

bool chk_arena_push(Arena* a, Size size, void** out) {
    if (!a) { return false; }
    if (!size) { return false; }
    if (!out) { return false; }

    if (a->size - a->used < size) { return false; }

    *out = a->data + a->used;
    a->used += size;

    return true;
}
