#include <chk/core/log.h>
#include <chk/core/print.h>

#include <cwalk.h>

void chk_impl_log_header(LogSev sev, const char* sender, const char* file,
                         U32 line, const char* func) {
    const char* sev_name = "Unknown";
    switch (sev) {
        case LogSev_Info: sev_name = "Info"; break;
        case LogSev_Warn: sev_name = "Warn"; break;
        case LogSev_Error: sev_name = "Error"; break;
    }

    const char*        fname;
    struct cwk_segment seg;
    if (!cwk_path_get_last_segment(file, &seg)) {
        fname = file;
    } else {
        fname = seg.begin;
    }

    chk_print_f("[%s] [%s] [%s:%d:%s] ", sev_name, sender, fname, line, func);
}

void chk_impl_log(LogSev sev, const char* sender, const char* msg,
                  const char* file, U32 line, const char* func) {
    chk_impl_log_header(sev, sender, file, line, func);
    chk_print_f("%s\n", msg);
}

void chk_impl_log_v(LogSev sev, const char* sender, const char* msg,
                    const char* file, U32 line, const char* func,
                    va_list args) {
    chk_impl_log_header(sev, sender, file, line, func);
    va_list args_copy;
    va_copy(args_copy, args);
    chk_print_v(msg, args_copy);
    va_end(args_copy);

    chk_print("\n");
}

void chk_impl_log_f(LogSev sev, const char* sender, const char* msg,
                    const char* file, U32 line, const char* func, ...) {
    va_list args;
    va_start(args, func);
    chk_impl_log_v(sev, sender, msg, file, line, func, args);
    va_end(args);
}
