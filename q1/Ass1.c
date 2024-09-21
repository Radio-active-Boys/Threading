#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

pthread_mutex_t mutex;

void *mythread(void *arg)
{
    pthread_mutex_lock(&mutex);
    printf("thread id %ld\n",(long)arg);
    pthread_mutex_unlock(&mutex);
    pthread_exit(NULL);
}

int main(int args, char *argv[])
{
    long n = 10;
    pthread_t threads[n];
    for(long i = 0; i < n;i++)
    {
        pthread_create(&threads[i],NULL,mythread,(long* )i);
        pthread_join(threads[i],NULL);
    }
    return 0;
}