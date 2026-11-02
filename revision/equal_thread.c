#include <stdio.h>
#include <pthread.h>

void* foo(void* thread1)
{
    pthread_t threadID = pthread_self();

    printf("%s", (char*)thread1);
    return NULL;
}


int main(void)
{
    pthread_t thread1;
    pthread_t thread2;

    pthread_create(&thread1, NULL, foo, (void*)"thread1 execution\n");
    pthread_create(&thread2, NULL, foo, (void*)"thread1 execution\n");

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    if (pthread_equal(thread1, thread2))
        printf("equal\n");
    else
        printf("different\n");

    printf("finishing operation\n");

    return(0);
}