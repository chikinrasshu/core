#include <chk/core/mem.h>

#include <stdlib.h>

void* chk_allocate(Size amount) {
    return malloc(amount);
}

void* chk_reallocate(void* ptr, Size new_size) {
    return realloc(ptr, new_size);
}

void chk_free(void* ptr) {
    free(ptr);
}
