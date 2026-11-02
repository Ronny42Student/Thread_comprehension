#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void* foo(void* thread1){
    while (1)
    {
        printf("%s", (char*)thread1);
        sleep(1);
    }
    return NULL;
}

int main(void)
{
    pthread_t   thread1;

    pthread_create(&thread1, NULL, foo, (void*)"ceci est une execution de thread\n");
    sleep(5);

    // demander d'annuler le thread apres 5 secondes
    pthread_cancel(thread1);

    pthread_join(thread1, NULL);

    printf("finishing compilation\n");
    return (0);
}