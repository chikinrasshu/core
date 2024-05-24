#pragma once

#include <chk/core/types.h>

#include <stdarg.h>

typedef enum LogSev {
    LogSev_Info,
    LogSev_Warn,
    LogSev_Error,
} LogSev;

void chk_impl_log(LogSev sev, const char* sender, const char* msg,
                  const char* file, U32 line, const char* func);
void chk_impl_log_v(LogSev sev, const char* sender, const char* msg,
                    const char* file, U32 line, const char* func, va_list args);
void chk_impl_log_f(LogSev sev, const char* sender, const char* msg,
                    const char* file, U32 line, const char* func, ...);

#define chk_info(sender, msg)                                                  \
    chk_impl_log(LogSev_Info, (sender), (msg), __FILE__, __LINE__, __func__)
#define chk_info_v(sender, msg, args)                                          \
    chk_impl_log_v(LogSev_Info, (sender), (msg), __FILE__, __LINE__, __func__, \
                   (args))
#define chk_info_f(sender, msg, ...)                                           \
    chk_impl_log_f(LogSev_Info, (sender), (msg), __FILE__, __LINE__, __func__, \
                   __VA_ARGS__)

#define chk_warn(sender, msg)                                                  \
    chk_impl_log(LogSev_Warn, (sender), (msg), __FILE__, __LINE__, __func__)
#define chk_warn_v(sender, msg, args)                                          \
    chk_impl_log_v(LogSev_Warn, (sender), (msg), __FILE__, __LINE__, __func__, \
                   (args))
#define chk_warn_f(sender, msg, ...)                                           \
    chk_impl_log_f(LogSev_Warn, (sender), (msg), __FILE__, __LINE__, __func__, \
                   __VA_ARGS__)

#define chk_error(sender, msg)                                                 \
    chk_impl_log(LogSev_Error, (sender), (msg), __FILE__, __LINE__, __func__)
#define chk_error_v(sender, msg, args)                                         \
    chk_impl_log_v(LogSev_Error, (sender), (msg), __FILE__, __LINE__,          \
                   __func__, (args))
#define chk_error_f(sender, msg, ...)                                          \
    chk_impl_log_f(LogSev_Error, (sender), (msg), __FILE__, __LINE__,          \
                   __func__, __VA_ARGS__)
