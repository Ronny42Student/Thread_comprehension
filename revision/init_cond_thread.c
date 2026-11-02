#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

/*
    pthread_cond_init(): est un mecanisme de synchronisation qui permet a un thread de se mettre en pause
    et d'attendre qu'un autre thread lui envoie un signal indiquant qu'un evenement s'est produit.

    Cela evite le gaspillage processeur lie a l'attente active (les boucles whiles continus)
*/

pthread_mutex_t mutex;
pthread_cond_t cond;
int travail_termine = 0;

void* thread_attente(void* thread)
{
    pthread_mutex_lock(&mutex);

    // on attend que la condition n'est pas remplie
    while (!travail_termine)
    {
        pthread_cond_wait(&cond, &mutex);
    }

    printf("Thread: le travail est termine, je reprends la main !\n");
    pthread_mutex_unlock(&mutex);

    return (NULL);
}

int main(void)
{
    pthread_t thread;

    // initialisation du mutex et de la variable de condition
    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&cond, NULL);

    pthread_create(&thread, NULL, thread_attente, NULL);

    // simulation d'un traitement dans le thread principal
    sleep(2);

    pthread_mutex_lock(&mutex);
    travail_termine = 1;        // modification de la condition
    pthread_cond_signal(&cond); // Reveil le thread en attente
    pthread_mutex_unlock(&mutex);


    pthread_join(thread, NULL);

    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond);

    return (0);
}