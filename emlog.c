#include<stdio.h>
#include<stdlib.h>
#include<stdarg.h>
#include"emlog.h"

static char *getLogLevel(const int level)
{
    switch(level){
        case LOG_DEBUG:
            return  "LOG_DEBUG";
        case LOG_INFORMATION:
            return "LOG_INFORMATION";
        case LOG_WARNING:
            return "LOG_WARNING";
        case LOG_ERROR:
            return "LOG_ERROR";
        default:
            return "UNKNOWN";
    }
}

void EM_LOG(const int level, const char* filename, const char* function, const int line, const char* format, ...)
{
    //指向参数地址的指针
    va_list args;
    //获取format内存首地址，交给args
    va_start(args, format);
    int size = vsnprintf(NULL, 0, format, args) + 1;
    //printf("size = %d\n", size);
    char buffer[size];
    vsnprintf(buffer, sizeof(buffer), format, args);
    //将args指针置为0
    va_end(args);

    if(level >= LOG_LEVEL){
        printf("[%s][%s:%s():%d] %s\n", getLogLevel(level), filename, function, line, buffer);
    }
}