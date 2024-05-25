#pragma once

#include <chk/core/types.h>

void* chk_allocate(Size amount);
void* chk_reallocate(void* ptr, Size new_size);
void  chk_free(void* ptr);

#define chk_kilobytes(N) (1024ULL * (N))
#define chk_megabytes(N) (1024ULL * chk_kilobytes(N))
#define chk_gigabytes(N) (1024ULL * chk_megabytes(N))
#define chk_terabytes(N) (1024ULL * chk_gigabytes(N))
