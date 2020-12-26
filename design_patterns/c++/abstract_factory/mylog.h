#ifndef MYLOG_H
#define MYLOG_H

#include <stdio.h>
#include <unistd.h>
#include <sys/syscall.h>
#include <sys/types.h>
#include <time.h>
#include <string.h>


#define gettid() syscall(__NR_gettid)

#define COLOUREND            "\e[0m"
#define NONE                 "\e[0m"
#define BLACK                "\e[0;30m"
#define L_BLACK              "\e[1;30m"
#define RED                  "\e[0;31m"
#define L_RED                "\e[1;31m"
#define GREEN                "\e[0;32m"
#define L_GREEN              "\e[1;32m"
#define BROWN                "\e[0;33m"
#define YELLOW               "\e[1;33m"
#define BLUE                 "\e[0;34m"
#define L_BLUE               "\e[1;34m"
#define PURPLE               "\e[0;35m"
#define L_PURPLE             "\e[1;35m"
#define CYAN                 "\e[0;36m"
#define L_CYAN               "\e[1;36m"
#define GRAY                 "\e[0;37m"
#define WHITE                "\e[1;37m"

#define BOLD                 "\e[1m"
#define UNDERLINE            "\e[4m"
#define BLINK                "\e[5m"
#define REVERSE              "\e[7m"
#define HIDE                 "\e[8m"
//#define CLEAR                "\e[2J"
#define CLRLINE              "\r\e[K" //or "\e[1K\r"


#define __FILENAME__ (strrchr(__FILE__, '/') ? (strrchr(__FILE__, '/') + 1):__FILE__)




//A Assert
#define logA(format, ...) fprintf(stderr, "\033[35m[A/LOG]  [%s: %d : (%s)]   " format"\033[0m\n", __FILENAME__, __LINE__ , __FUNCTION__, ##__VA_ARGS__);
//E Error
#define logE(format, ...) fprintf(stderr, "\033[31m[E/LOG]  [%s: %d : (%s)]   " format"\033[0m\n", __FILENAME__, __LINE__ , __FUNCTION__, ##__VA_ARGS__);
//W Warnning
#define logW(format, ...) fprintf(stderr, "\033[33m[W/LOG]  [%s: %d : (%s)]   " format"\033[0m\n", __FILENAME__, __LINE__ , __FUNCTION__, ##__VA_ARGS__);
//D Debug
#define logD(format, ...) fprintf(stderr, "\033[32m[D/LOG]  [%s: %d : (%s)]   " format"\033[0m\n", __FILENAME__, __LINE__ , __FUNCTION__, ##__VA_ARGS__);
//I Info
#define logI(format, ...) fprintf(stderr, "\033[36m[I/LOG]  [%s: %d : (%s)]   " format"\033[0m\n", __FILENAME__, __LINE__ , __FUNCTION__, ##__VA_ARGS__);
//V Verbose
#define logV(format, ...) fprintf(stderr, "\033[34m[V/LOG]  [%s: %d : (%s)]   " format"\033[0m\n", __FILENAME__, __LINE__ , __FUNCTION__, ##__VA_ARGS__);
//T Trace
#define logT(format, ...) fprintf(stderr, "\033[37m[T/LOG]  [%s: %d : (%s)]   " format"\033[0m\n", __FILENAME__, __LINE__ , __FUNCTION__, ##__VA_ARGS__);

#define DEBUG 1 


#define LOGA(fmt, args...) { \
	if(DEBUG==1)\
	{\
        time_t timep; \
        struct tm *p; \
		time(&timep); \
		p=localtime(&timep); \
        fprintf(stderr, "\033[35m[%02d:%02d:%02d PID:%ld TID:%ld A/LOG]  [%s: %d : (%s)]  " fmt"\033[0m\n", \
		p->tm_hour, \
		p->tm_min, \
		p->tm_sec, \
		getpid(), \
		gettid(), \
		__FILENAME__, \
		__LINE__, \
		__FUNCTION__, ##args); \
	} \
}

#define LOGE(fmt, args...) { \
        if(DEBUG==1)\
        {\
            time_t timep; \
            struct tm *p; \
            time(&timep); \
            p=localtime(&timep); \
            fprintf(stderr, "\033[31m[%02d:%02d:%02d PID:%ld TID:%ld E/LOG]  [%s: %d : (%s)]  " fmt"\033[0m\n", \
            p->tm_hour, \
            p->tm_min, \
            p->tm_sec, \
			getpid(), \
            gettid(), \
            __FILENAME__, \
            __LINE__, \
            __FUNCTION__, ##args); \
        } \
}

#define LOGW(fmt, args...) { \
        if(DEBUG==1)\
        {\
            time_t timep; \
            struct tm *p; \
                time(&timep); \
                p=localtime(&timep); \
                fprintf(stderr, "\033[33m[%02d:%02d:%02d PID:%ld TID:%ld W/LOG]  [%s: %d : (%s)]  " fmt"\033[0m\n", \
                p->tm_hour, \
                p->tm_min, \
                p->tm_sec, \
				getpid(), \
                gettid(), \
                __FILENAME__, \
                __LINE__, \
                __FUNCTION__, ##args); \
        } \
}

#define LOGD(fmt, args...) { \
        if(DEBUG==1)\
        {\
            time_t timep; \
            struct tm *p; \
                time(&timep); \
                p=localtime(&timep); \
                fprintf(stderr, "\033[32m[%02d:%02d:%02d PID:%ld TID:%ld D/LOG]  [%s: %d : (%s)]  " fmt"\033[0m\n", \
                p->tm_hour, \
                p->tm_min, \
                p->tm_sec, \
				getpid(), \
                gettid(), \
                __FILENAME__, \
                __LINE__, \
                __FUNCTION__, ##args); \
        } \
}

#define LOGI(fmt, args...) { \
        if(DEBUG==1)\
        {\
            time_t timep; \
            struct tm *p; \
                time(&timep); \
                p=localtime(&timep); \
                fprintf(stderr, "\033[36m[%02d:%02d:%02d PID:%ld TID:%ld I/LOG]  [%s: %d : (%s)]  " fmt"\033[0m\n", \
                p->tm_hour, \
                p->tm_min, \
                p->tm_sec, \
				getpid(), \
                gettid(), \
                __FILENAME__, \
                __LINE__, \
                __FUNCTION__, ##args); \
        } \
}


#define LOGV(fmt, args...) { \
        if(DEBUG==1)\
        {\
            time_t timep; \
            struct tm *p; \
                time(&timep); \
                p=localtime(&timep); \
                fprintf(stderr, "\033[34m[%02d:%02d:%02d PID:%ld TID:%ld V/LOG]  [%s: %d : (%s)]  " fmt"\033[0m\n", \
                p->tm_hour, \
                p->tm_min, \
                p->tm_sec, \
				getpid(), \
                gettid(), \
                __FILENAME__, \
                __LINE__, \
                __FUNCTION__, ##args); \
        } \
}

#define LOGT(fmt, args...) { \
        if(DEBUG==1)\
        {\
            time_t timep; \
            struct tm *p; \
                time(&timep); \
                p=localtime(&timep); \
                fprintf(stderr, "\033[37m[%02d:%02d:%02d PID:%ld TID:%ld T/LOG]  [%s: %d : (%s)]  " fmt"\033[0m\n", \
                p->tm_hour, \
                p->tm_min, \
                p->tm_sec, \
				getpid(), \
                gettid(), \
                __FILENAME__, \
                __LINE__, \
                __FUNCTION__, ##args); \
        } \
}


/*
#define clean_errno() (errno == 0 ? "NONE" : strerror(errno))
#define log_err(M,...) fprintf(stderr," "RED" [ERROR] (%s:%d: errno: %s) " M " "COLOUREND" \n",__FILENAME__, __LINE__, clean_errno(), ##__VA_ARGS__)
#define log_warn(M, ...) fprintf(stderr, " "YELLOW" [WARN] (%s:%d: errno: %s) " M " "COLOUREND" \n", __FILENAME__, __LINE__, clean_errno(), ##__VA_ARGS__)
#define log_debug(M, ...) fprintf(stderr, " "CYAN" [DEBUG] (%s:%d) " M " "COLOUREND"\n", __FILENAME__, __LINE__, ##__VA_ARGS__)
#define log_info(M, ...) fprintf(stderr, " "CYAN" [INFO] (%s:%d) " M " "COLOUREND"\n", __FILENAME__, __LINE__, ##__VA_ARGS__)
#define log_info(M, ...) fprintf(stderr, " "CYAN" [VERB] (%s:%d) " M " "COLOUREND"\n", __FILENAME__, __LINE__, ##__VA_ARGS__)
*/
#endif
