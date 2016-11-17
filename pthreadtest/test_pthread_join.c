#include <stdio.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/time.h>
#include <unistd.h>

#define MAX 5

#define TRAND(limit,n) {struct timeval t;\
                        gettimeofday(&t, (void*)NULL);\
                        (n) = rand_r((unsigned *) &t.tv_usec) % (limit) +1;}

void *say_it(void *word)
{
	printf("my id is %d\n", pthread_self());
    int i, numb;
    TRAND(MAX,numb);
    printf("\n %d %s ", numb, (char *)word);
    for (i = 0; i < numb; ++i)
    {
        sleep(1);
        printf("%s", (char*)word);
    }
	
	printf("thread %d exit\n", pthread_self());
    return (void*)NULL;
}

int main(int argc, char **argv)
{
    int i;
    pthread_t thread_id[MAX];
    int status, *p_status = &status;

    if (argc > MAX+1)
    {
        fprintf(stderr, "%s arg1, arg2, ...arg %d\n", *argv, MAX);
        exit(1);
    }

    printf("DisPlaying\n");
    for (i = 0; i < argc -1; i++)
    {
        if (pthread_create(&thread_id[i], NULL, say_it, (void *)argv[i+1]) > 0)
        {
            fprintf(stderr, "pthread_create failure\n"), exit(2);
        }
    }

    for (i = 0; i < argc -1; ++i)
    {
        if (pthread_join(thread_id[i], (void**)p_status) != 0)
        {
            fprintf(stderr, "pthread_join failure\n");
        }
        printf("\n Thread %d returns %d\n", thread_id[i], status);
    }

	printf("done\n");

    return 0;
}
