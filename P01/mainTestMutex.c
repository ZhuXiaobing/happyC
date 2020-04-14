#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

void * print_message_function(void *);

long total = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

int main(void) {
    int temp1, temp2;
    void * ret_val;
    int ret_th1, ret_th2;
    char * msg1 = "message1";
    char * msg2 = "message2";
    pthread_t th1, th2;
    ret_th1 = pthread_create(&th1, NULL, print_message_function, msg1);
    ret_th2 = pthread_create(&th2, NULL, print_message_function, msg2);
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
    temp1 = pthread_join(th1, ret_val);
    printf("th1 ret_val is %d\n", (int *)ret_val);
    printf("th1 temp1 is %d\n", temp1);
    if (temp1 != 0) {
        printf("can't join th1.\n");
    }
    printf("th1 exe end.\n");

    temp2 = pthread_join(th2, ret_val);
    printf("th2 ret_val is %d\n", (int *)ret_val);
    printf("th2 temp2 is %d\n", temp2);
    if (temp2 != 0) {
        printf("can't join th2.\n");
    }
    printf("th2 exe end.\n");
    printf("the total is %ld\n", total);
}

void * print_message_function(void * ptr) {
    int lock = pthread_mutex_lock(&mutex);
    if (lock == 0) {
        for(int i = 0; i < 100000; i ++) {
            total++;
        }
    }
    int unlock = pthread_mutex_unlock(&mutex);
}
