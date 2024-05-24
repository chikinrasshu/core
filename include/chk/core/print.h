#pragma once

#include <chk/core/types.h>

#include <stdarg.h>

void chk_print(const char* msg);
void chk_print_v(const char* msg, va_list args);
void chk_print_f(const char* msg, ...);
