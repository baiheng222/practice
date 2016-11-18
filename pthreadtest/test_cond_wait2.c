/*条件变量 
互斥锁一个明显的缺点是它只有两种状态：锁定和非锁定。而条件变量通过允许线程阻塞和等待另一个线程发送信号的方法弥补了互斥锁的不足， 
它常和互斥锁一起使用。使用时，条件变量被用来阻塞一个线程，当条件不满足时，线程往往解开相应的互斥锁并等待条件发生变化。一旦其它的 
某个线程改变了条件变量，它将通知相应的条件变量唤醒一个或多个正被此条件变量阻塞的线程。这些线程将重新锁定互斥锁并重新测试条件是否 
满足。一般说来，条件变量被用来进行线程间的同步。 
cond1.c 
gcc cond1.c -o cond1 -lpthread 
./cond1
*/   

#include <stdio.h>  
#include <pthread.h>  
#include <unistd.h>  
  
pthread_mutex_t count_lock;//自旋锁  
pthread_cond_t count_nonzero;//条件锁  
unsigned count = 0;  
  
void *decrement_count(void *arg)  
{  
    pthread_mutex_lock(&count_lock);//等待线程:1使用pthread_cond_wait前要先加锁  
    printf("decrement_count get count_lock\n");  
    while(count == 0)  
    {  
        printf("decrement_count count == 0 \n");  
        printf("decrement_count before cond_wait \n");  
        pthread_cond_wait(&count_nonzero, &count_lock);//2pthread_cond_wait内部会解锁，然后等待条件变量被其它线程激活  
        printf("decrement_count after cond_wait \n");  
    }  
    printf("tid1:count--\n");  
    count = count - 1;  
    printf("tid1:count= %d \n", count);  
    pthread_mutex_unlock(&count_lock);  
}  
  
void *increment_count(void *arg)  
{  
    pthread_mutex_lock(&count_lock);         //激活线程：1加锁（和等待线程用同一个锁）  
    printf("increment_count get count_lock \n");  
    if(count == 0)  
    {  
        printf("increment_count before cond_signal \n");  
        pthread_cond_signal(&count_nonzero);           //2pthread_cond_signal发送信号  
        printf("increment_count after cond_signal \n");  
    }  
	printf("tid2:count++\n");  
    count = count + 1;  
    printf("tid2:count= %d \n", count);  
    pthread_mutex_unlock(&count_lock);//3解锁.激活线程的上面三个操作在运行时间上都在等待线程的pthread_cond_wait函数内部。  
}  
  
int main(void)  
{  
    pthread_t tid1, tid2;  
  
    pthread_mutex_init(&count_lock, NULL);  
    pthread_cond_init(&count_nonzero, NULL);  
  
    pthread_create(&tid1, NULL, decrement_count, NULL);  
	printf("tid1 decrement is created,begin sleep 2s \n");  
    sleep(2);  
	printf("after sleep 2s, start creat tid2 increment \n");  
    pthread_create(&tid2, NULL, increment_count, NULL);  
	printf("after tid2 increment is created,begin sleep 10s \n");  
    sleep(5);  
	printf("after sleep 5s,begin exit!\n");  
    pthread_exit(0);  
  
    return 0;  
}  
