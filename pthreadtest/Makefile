EXECTUABLE = test_pthread_join test_pthread_mutex test_pthread_mutex_multiprocess test_cond_wait test_cond_wait2
CFLAGS = -g -Wall
CC = gcc
CXX = g++

all:$(EXECTUABLE)

test_pthread_join:test_pthread_join.c
	$(CC) $(CFLAGS) -o test_pthread_join test_pthread_join.c -lpthread

test_pthread_mutex:test_pthread_mutex_singleprocess.c
	$(CC) $(CFLAGS) -o test_pthread_mutex test_pthread_mutex_singleprocess.c -lpthread

test_pthread_mutex_multiprocess:test_pthread_mutex_multiprocess.c
	$(CC) $(CFLAGS) -o test_pthread_mutex_multiprocess test_pthread_mutex_multiprocess.c -lpthread

test_cond_wait:test_cond_wait.c
	$(CC) $(CFLAGS) -o test_cond_wait test_cond_wait.c -lpthread

test_cond_wait2:test_cond_wait2.c
	$(CC) $(CFLAGS) -o test_cond_wait2 test_cond_wait2.c -lpthread
#threadpool11:ThreadPoolCpp11/main.cpp ThreadPoolCpp11/ThreadPool.cpp
#    g++ $(CFLAGS) -o threadpool11 -std=c++11 ThreadPoolCpp11/main.cpp ThreadPoolCpp11/ThreadPool.cpp -lpthread

clean:
	-rm -f $(EXECTUABLE) *~

