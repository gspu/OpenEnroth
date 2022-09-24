#include <stdarg.h>
#include <stdio.h>
#include <time.h>

#include "Engine/Engine.h"
#include "Engine/Log.h"

#include "Platform/Api.h"

bool Log::Initialize() { return this->initialized = OS_OpenConsole(); }

void Log::Info(const char *pFormat, ...) {
    if (this->initialized) {
        va_list args;
        char pMsg[8192];

        va_start(args, pFormat);
        vsnprintf(pMsg, 8192, pFormat, args);
        va_end(args);

        time_t t = time(NULL);
        struct tm tm = *localtime(&t);
        printf("[%04d/%02d/%02d %02d:%02d:%02d] %s\n", tm.tm_year + 1900,
               tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec,
               pMsg);
    }
}

void Log::Warning(const char *pFormat, ...) {
    if (this->initialized) {
        va_list args;
        char pMsg[8192];

        va_start(args, pFormat);
        vsnprintf(pMsg, 8192, pFormat, args);
        va_end(args);

        time_t t = time(NULL);
        struct tm tm = *localtime(&t);
        fprintf(stderr, "[%04d/%02d/%02d %02d:%02d:%02d] %s\n", tm.tm_year + 1900,
               tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec,
               pMsg);
    }
}

//----- (004BE386) --------------------------------------------------------
void log_error(const char *pMessage) {
    FILE *f = fopen(MakeDataPath("errorlog.txt").c_str(), "a");
    if (f) {
        fprintf(f, "%s\n", pMessage);
        fclose(f);
        fflush(f);
    }
}
