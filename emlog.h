#ifndef _EMLOG_H_
#define _EMLOG_H_

#define LOG_LEVEL   LOG_INFORMATION
#define EMLOG(level, format...) EM_LOG(level, __FILE__, __FUNCTION__, __LINE__, format)

typedef enum{
    LOG_DEBUG,
    LOG_INFORMATION,
    LOG_WARNING,
    LOG_ERROR,
} EM_LOG_LEVEL;

void EM_LOG(const int level, const char* filename, const char* function, const int line, const char* format, ...);

#endif