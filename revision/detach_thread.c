#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

void* foo(void* thread1)
{
    printf("%s", (char*)thread1);
    sleep(2);
    printf("thread1 finished\n");
    return NULL;
}


int main(void)
{
    pthread_t   thread1;

    pthread_create(&thread1, NULL, foo, (void*)"execution thread1\n");

    // au premier tour, il va retirer l'execution de la tache
    pthread_detach(thread1);

    printf("le thread principale continue\n");
    sleep(3);
    return (0);
}