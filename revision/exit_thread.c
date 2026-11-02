#include <pthread.h>
#include <stdio.h>

void *foo(void* thread1)
{
    printf("%s", (char*)thread1);

    // terminer l'execution
    pthread_exit(NULL);

    printf("ceci ne sera pas executer");
    return NULL;
}

int main(void)
{
    pthread_t thread1;

    pthread_create(&thread1, NULL, foo, (void*)"Le thread en cours d\'execution \n");
    pthread_join(thread1, NULL);
    return (0);
}