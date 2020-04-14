#include <stdlib.h>
#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>

#define ARRSIZE 10

void* producer (void);
void* consumer (void);

sem_t sem;
int arr[ARRSIZE];

int main(void) {
    void * ret_val;
    int ret_th1, ret_th2;
    pthread_t th1, th2;
    sem_init(&sem, 0, 0);
    ret_th1 = pthread_create(&th1, NULL, producer, NULL);
    ret_th2 = pthread_create(&th2, NULL, consumer, NULL);
    if (ret_th1 != 0) {
        printf("create th1 error.\n");
        exit(EXIT_FAILURE);
    } else {
        printf("create th1 success.\n");
    }
    if (ret_th2 != 0) {
        printf("create th1 error.\n");
        exit(EXIT_FAILURE);
    } else {
        printf("create th1 success.\n");
    }
    pthread_join(th1, NULL);
    pthread_join(th2, NULL);
    sem_destroy(&sem);
}

void* producer (void) {
    int i = 0;
    while(i < ARRSIZE){
        arr[i] = i;
        printf("put value %d\n", i);
        i ++ ;
        sem_post(&sem);
    }
}
void* consumer (void) {
    int i = 0;
    while(i < ARRSIZE) {
        sem_wait(&sem);
        printf("get value %d\n", arr[i]);
        i ++;
    }
}
