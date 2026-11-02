#include <stdio.h>
#include <sys/time.h>
#include <time.h>
#include <unistd.h>

int main(void)
{
    struct timeval tv;
    struct timespec ts;

    // pour gettimeofday
    gettimeofday(&tv, NULL);

    printf("Secondes : %ld\n", tv.tv_sec);
    printf("Microsecondes : %ld\n", tv.tv_usec);

    // un thread en pause pendant 500 millisecondes (500000 microsecondes)
    usleep(500000);

    // pour clock_gettime
    clock_gettime(CLOCK_MONOTONIC, &ts);

    printf("Secondes: %ld\n", ts.tv_sec);
    printf("NanoSecondes: %ld\n", ts.tv_nsec);

    return (0);
}