/* FOREGROUND */
#define RST  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"

#define FRED(x) KRED x RST
#define FGRN(x) KGRN x RST
#define FYEL(x) KYEL x RST
#define FBLU(x) KBLU x RST
#define FMAG(x) KMAG x RST
#define FCYN(x) KCYN x RST
#define FWHT(x) KWHT x RST

#define BOLD(x) "\x1B[1m" x RST
#define UNDL(x) "\x1B[4m" x RST

#include "../Platform/Typedef.hpp"

#if   defined(AE_LINUX)

    #define AE_LOG(x)         printf("%s %s\n", LOG_STR,         FWHT(x))
    #define AE_LOG_ERROR(x)   printf("%s %s\n", LOG_ERROR_STR,   FRED(x))
    #define AE_LOG_WARNING(x) printf("%s %s\n", LOG_WARNING_STR, FYEL(x))
    #define AE_LOG_SUCCESS(x) printf("%s %s\n", LOG_SUCCESS_STR, FGRN(x))

#elif defined(AE_WINDOWS)

    #include <windows.h>

    #define WIN_CON_COL(color) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
    #define WIN_CON_RES        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

    #define AE_LOG(x)         WIN_CON_RES;     printf("%s %s\n", LOG_STR,         x); WIN_CON_RES
    #define AE_LOG_ERROR(x)   WIN_CON_COL(12); printf("%s %s\n", LOG_ERROR_STR,   x); WIN_CON_RES
    #define AE_LOG_WARNING(x) WIN_CON_COL(14); printf("%s %s\n", LOG_WARNING_STR, x); WIN_CON_RES
    #define AE_LOG_SUCCESS(x) WIN_CON_COL(10); printf("%s %s\n", LOG_SUCCESS_STR, x); WIN_CON_RES

#endif // AE_LINUX

