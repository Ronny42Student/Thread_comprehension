#include <pthread.h>
#include <stdio.h>

void* process(void* thread1){
    printf("%s\n", (char*)thread1);
    return NULL;
}

int main(void)
{
    pthread_t thread1;
    pthread_t thread2;

    pthread_create(&thread1, NULL, process, (void*)"thread1 is running");

    pthread_create(&thread2, NULL, process, (void*)"thread2 is running");

    // wait thread1 to finish
    pthread_join(thread1, NULL);

    // wait thread2 to finish
    // utilisee pour la synchronistaion d'un thread
    pthread_join(thread2, NULL);

    printf("finish");
    return (0);
}