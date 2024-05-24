#include <chk/core/print.h>

#include <stdio.h>

void chk_print(const char* msg) { printf("%s", msg); }

void chk_print_v(const char* msg, va_list args) {
    char g_chk_print_v_buffer[1024];

    va_list args_copy;
    va_copy(args_copy, args);
    vsnprintf(g_chk_print_v_buffer, sizeof(g_chk_print_v_buffer), msg,
              args_copy);
    va_end(args_copy);

    chk_print(g_chk_print_v_buffer);
}

void chk_print_f(const char* msg, ...) {
    va_list args;
    va_start(args, msg);
    chk_print_v(msg, args);
    va_end(args);
}
