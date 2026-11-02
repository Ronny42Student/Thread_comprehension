#include <stdio.h>
#include <pthread.h>
#include <errno.h>
#include <time.h>

pthread_mutex_t mutex;
pthread_cond_t cond;

void* foo(void* thread)
{
    struct  timespec ts;
    clock_gettime(CLOCK_REALTIME, &ts);
    ts.tv_sec += 2;

    pthread_mutex_lock(&mutex);
    
    int ret = pthread_cond_timedwait(&cond, &mutex, &ts);
    if (ret == ETIMEDOUT)
    {
        printf("le temps est ecoule sans que le signal n'arrive");
    }

    pthread_mutex_unlock(&mutex);
    printf("%s", (char*)thread);

    return NULL;
}

int main(void)
{
    pthread_t thread;
    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&cond, NULL);

    pthread_create(&thread, NULL, foo, (void*)"hello depuis thread");
    
    pthread_join(thread, NULL);

    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond);

    return (0);
}