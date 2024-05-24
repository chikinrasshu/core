#pragma once

#include <chk/core/types.h>

void* chk_allocate(Size amount);
void* chk_reallocate(void* ptr, Size new_size);
void chk_free(void* ptr);
