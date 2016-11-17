//
// Created by baiheng222 on 16-11-17.
//
#include <stdio.h>
#include <ctype.h>
#include <pthread.h>

#define MAX 5

pthread_mutex_t lock_it = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t  write_it = PTHREAD_COND_INITIALIZER;

typedef enum {FALSE, TRUE} boolean;
typedef struct
{
    char buffer[MAX];
    int how_many;
}BUFFER;

BUFFER share = {"", 0};
//void *read_some(void *), *write_some(void *);
boolean finished = FALSE;

void *read_some(void *p)
{
    int ch;

    printf("R %2d: Starting\n", pthread_self());

    while(!finished)
    {
        pthread_mutex_lock(&lock_it);
        if (share.how_many != MAX)
        {
            ch = getc(stdin);
            if (ch == EOF)
            {
                share.buffer[share.how_many] = NULL;
                share.how_many = MAX;
                finished = TRUE;
                printf("R %2d: Signaling done\n", pthread_self());
                pthread_cond_signal(&write_it);
                pthread_mutex_unlock(&lock_it);
                break;
            }
            else
            {
                share.buffer[share.how_many++] = ch;
                printf("R %2d: Got char [%c]\n", pthread_self(), isalnum(ch) ? ch : '#');
                if (share.how_many == MAX)
                {
                    printf("R %2d: Signaling full\n", pthread_self());
                    pthread_cond_signal(&write_it);
                }
            }
        }
        pthread_mutex_unlock(&lock_it);
    }
    printf("R %2d: Exiting\n", pthread_self());
    return NULL;
}

void *write_some(void *p)
{
    int i;
    printf("W %2d: Starting \n", pthread_self());
    while(!finished)
    {
        pthread_mutex_lock(&lock_it);
        printf("\nW %2d: Waiting\n", pthread_self());
        while(share.how_many != MAX)
        {
            pthread_cond_wait(&write_it, &lock_it);
        }

        printf("W %2d: Writing buffer\n", pthread_self());

        for (i = 0; share.buffer && share.how_many; ++i, share.how_many--)
        {
            putchar(share.buffer[i]);
        }

        pthread_mutex_unlock(&lock_it);

    }

    printf("W %2d: Exiting\n", pthread_self());
    return NULL;
}

int main(int argc, char**argv)
{
    pthread_t t_read, t_write;

    pthread_create(&t_read, NULL, read_some, NULL);
    pthread_create(&t_write, NULL, write_some, NULL);
    pthread_join(t_write, NULL);
    pthread_mutex_destroy(&lock_it);
    pthread_cond_destroy(&write_it);

    return 0;
}

