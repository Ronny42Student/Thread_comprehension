#include <stdio.h>
#include <pthread.h>


void* foo(void* thread1)
{
    pthread_t   currentThread = pthread_self(); // prend l'ID de type thread

    printf("current thread ID %lu\n", (unsigned long)currentThread);
    printf("%s", (char*)thread1);
    return NULL;
}


int main(void)
{
    pthread_t   thread1;

    pthread_create(&thread1, NULL, foo, (void*)"thread1 execution");
    pthread_join(thread1, NULL);

    return (0);
}