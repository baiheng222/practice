#include "local_mutex.h"

struct timespec some_time = {0, 10000};
FILE *fptr;
pthread_mutex_t LOCK, *m_LOCK = &LOCK;
int setup, *s_shm = &setup, current, *c_shm = &current;

//产生一个随机数并写入一个文件中
void produce(void)
{
    int err, *n = NULL;
    printf("%2d P: attempting ot produce \t %3d\n", pthread_self(), getpid());
    FF;

    if (pthread_mutex_trylock(m_LOCK) != 0)
    {
        printf("%2d P: lock busy \t %3d\n", pthread_self(), getpid());
        FF;
        return;
    }

    n = (int *)malloc(sizeof(int) * 1);

	if (n == NULL)
	{
		printf("%2d P: malloc n error \t %3d\n", pthread_self(), getpid());
		return;
	}

    TRAND(MAX, *n);

    if ((fptr = fopen(BUFFER, "a")) == NULL)
    {
        perror(BUFFER);
        exit(101);
    }

    fprintf(fptr, "%3d", *n);
    fflush(fptr);
    fclose(fptr);
    printf("%2d P: The #[%2d] deposited \t %3d\n", pthread_self(), *n, getpid());
    FF;

    free(n);
	n = NULL;

    nanosleep(&some_time, NULL);

    if ((err = pthread_mutex_unlock(m_LOCK)) != 0)
    {
        fprintf(stderr, "P: unlock mutex failure %\n", err);
        exit(102);
    }

	printf("%2d P: thread exit! \t %3d\n", pthread_self(), getpid());

}


void consume(void)
{
    int err, *n = NULL;
    printf("%2d C: attempting to consume \t %3d\n", pthread_self(), getpid());

    if (pthread_mutex_trylock(m_LOCK) != 0)
    {
        printf("%2d C: lock busy \t %3d\n", pthread_self(), getpid());
        FF;
    }

    if ((fptr = fopen(BUFFER, "r+")) == NULL)
    {
        perror(BUFFER);
        exit(103);
    }

    fseek(fptr, *c_shm * 3, SEEK_SET);
    n = (int *)malloc(sizeof(int));
	
	if (n == NULL)
    {
        printf("%2d C: malloc n error \t %3d\n", pthread_self(), getpid());
        return;
    }

    *n = 0;
    fscanf(fptr, "%3d", n);

    if (*n > 0)
    {
        printf("%2d C: The # [%2d] obtained \t %3d\n", pthread_self(), *n, getpid());
        FF;
        fseek(fptr, *c_shm *3, SEEK_SET);
        fprintf(fptr, "%3d", -(*n));
        fflush(fptr);
        ++*c_shm;
    }
    else
    {
        printf("%2d C: no new # to consume \t %3d\n", pthread_self(), getpid());
        FF;
    }

    fclose(fptr);
    free(n);
	n = NULL;

    nanosleep(&some_time, NULL);

    if ((err = pthread_mutex_unlock(m_LOCK)) != 0)
    {
        fprintf(stderr, "C: unlock failure %d\n", err);
        exit(104);
    }

	printf("%2d C: thread exit \t %3d\n", pthread_self(), getpid());
}


void do_work(void)
{
    int i, n;

    if (!(*s_shm))
    {
        pthread_mutex_lock(m_LOCK);
        if (!(*s_shm)++)
        {
            printf("%2d : clearing the buffer \t %3d\n", pthread_self(), getpid());
            if ((fptr = fopen(BUFFER, "w+")) == NULL)
            {
                perror(BUFFER);
                exit(105);
            }
            fclose(fptr);
        }
        pthread_mutex_unlock(m_LOCK);
    }

    nanosleep(&some_time, NULL);

    for (i = 0; i < 10; ++i)
    {
        TRAND(2, n);
        switch(n)
        {
            case 1:
                produce();
                break;

            case 2:
                consume();
                break;
        }
        nanosleep(&some_time, NULL);
    }
}


//multi threads main
/*
int main(int argc, char **argv)
{
    int i, n;
    pthread_t worker[MAX];

    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s n_workers\n", *argv);
        exit(1);
    }

    pthread_mutex_init(m_LOCK, NULL);
    *s_shm = 0;
    *c_shm = 0;
    n = atoi(argv[1]) < MAX ? atoi(argv[1]) : MAX;

    for (i = 0; i < n; ++i)
    {
        pthread_create(&worker[i], NULL, (void *(*)(void *))do_work, (void*)NULL);
    }

    for (i = 0; i < n; ++i)
    {
        pthread_join(worker[i], (void **)NULL);
    }

    return 0;
}
*/

//multi process
int main(int argc, char **argv)
{
    pthread_mutexattr_t the_attr_obj;
    int i, n;
    int m_shmid, i_shmid;

    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s n_workers\n", *argv);
        return -1;
    }

    n = atoi(argv[1]) < MAX ? atoi(argv[1]) : MAX;

    if ((m_shmid = shmget(IPC_PRIVATE, sizeof(pthread_mutex_t), IPC_CREAT|0666)) < 0)
    {
        perror("shmget fail mutex\n");
        return -1;
    }

    if ((m_LOCK = (pthread_mutex_t *)shmat(m_shmid, 0, 0)) == (pthread_mutex_t*)-1)
    {
        perror("shmat fail mutex\n");
        return -1;
    }

    if ((i_shmid = shmget(IPC_PRIVATE, sizeof(int) * 2, IPC_CREAT | 0666 )) < 0)
    {
        perror("shmget fail ints\n");
        return -1;
    }

    if ((s_shm = (int *)shmat(i_shmid, 0, 0)) == (int *)-1)
    {
        perror("shat fail ints\n");
        return -1;
    }

    c_shm = s_shm + sizeof(int);
    *s_shm = 0;
    *c_shm = 0;

    pthread_mutexattr_init(&the_attr_obj);
    pthread_mutexattr_setpshared(&the_attr_obj, PTHREAD_PROCESS_SHARED);
    pthread_mutex_init(m_LOCK, &the_attr_obj);

    for (i = 0; i < n; ++i)
    {
        if (fork() == 0)
        {
            do_work();
            exit(2);
        }
    }

    while((n = (int)wait(NULL)) && n != -1)
    {
        ;
    }

    shmdt((char *)m_LOCK);
    shmdt((char *)s_shm);
    shmctl(m_shmid, IPC_RMID, (struct shmid_ds *)0);
    shmctl(i_shmid, IPC_RMID, (struct shmid_ds *)0);
    return 0;
}

