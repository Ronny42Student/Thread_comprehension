#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

// Voici comment initialiser, utiliser et detruire correctement 
// un mutex pour proteger le compteur partage

pthread_mutex_t lock; // declare un mutex
int counter = 0;

void* incrementer_counter(void* thread)
{
    int i = 0;

    pthread_mutex_lock(&lock);
    while (i < 100000)
    {
        i++;
        counter++;
    }
    pthread_mutex_unlock(&lock);

    return NULL;
}

int main(void)
{
    pthread_t thread1;
    pthread_t thread2;
    pthread_mutex_init(&lock, NULL);

    pthread_create(&thread1, NULL, incrementer_counter, NULL);
    pthread_create(&thread2, NULL, incrementer_counter, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("final counter value %d\n", counter);
    pthread_mutex_destroy(&lock);

    return (0);
}