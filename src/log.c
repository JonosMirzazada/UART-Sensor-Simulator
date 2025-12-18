#include "log.h"
#include <stdio.h>
#include <stdarg.h>

static LogLevel current_level = LOG_INFO;

void set_log_level(LogLevel level)
{
    current_level = level;
}

static void log_print(LogLevel level, const char *prefix,
                      const char *fmt, va_list args)
{
    if (level < current_level)
        return;

    printf("[%s] ", prefix);
    vprintf(fmt, args);
    printf("\n");
}

void log_debug(const char *fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    log_print(LOG_DEBUG, "DEBUG", fmt, args);
    va_end(args);
}

void log_info(const char *fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    log_print(LOG_INFO, "INFO", fmt, args);
    va_end(args);
}

void log_error(const char *fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    log_print(LOG_ERROR, "ERROR", fmt, args);
    va_end(args);
}
