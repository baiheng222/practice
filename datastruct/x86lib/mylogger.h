#ifndef _MYLOGGER_H
#define _MYLOGGER_H

#ifdef __cplusplus
extern "C" {
#endif

#define LOG_TAG     "MYLOGGER"

#include "elog.h"

#define LogA(...)       elog_a(LOG_TAG, __VA_ARGS__)
#define LogE(...)       elog_e(LOG_TAG, __VA_ARGS__)
#define LogW(...)       elog_w(LOG_TAG, __VA_ARGS__)
#define LogI(...)       elog_i(LOG_TAG, __VA_ARGS__)
#define LogD(...)       elog_d(LOG_TAG, __VA_ARGS__)
#define LogV(...)       elog_v(LOG_TAG, __VA_ARGS__)

void init_mylogger();
void set_filter_level(int lev);
void set_filter_tag(const char *tag);
void set_filter_keyword(const char *keyword);

#ifdef __cplusplus
}
#endif

#endif


