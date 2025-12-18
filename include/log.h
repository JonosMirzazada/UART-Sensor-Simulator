#ifndef LOG_H
#define LOG_H

typedef enum
{
    LOG_DEBUG = 0,
    LOG_INFO  = 1,
    LOG_ERROR = 2
} LogLevel;

void set_log_level(LogLevel level);

void log_debug(const char *fmt, ...);
void log_info(const char *fmt, ...);
void log_error(const char *fmt, ...);

#endif
