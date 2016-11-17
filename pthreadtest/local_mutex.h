#ifndef LOCAL_MUTEX_H
#define LOCAL_MUTEX_H
#define _REENTRANT

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/time.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define BUFFER  "./buffer"
#define MAX 99
#define TRAND(limit,n)  {struct timeval t;\
                            gettimeofday(&t, (void *)NULL);\
                            (n) = rand_r((unsigned *)&t.tv_usec) % limit +1;}
#define FF fflush(stdout)

#endif
