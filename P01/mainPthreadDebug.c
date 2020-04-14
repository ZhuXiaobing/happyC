#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>


void * print_message_function(void *);

long total = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

int main(void) {
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
        printf("create th2 error.\n");
        exit(EXIT_FAILURE);
    } else {
        printf("create th2 success.\n");
    }
    pthread_join(th1, NULL);
    pthread_join(th2, NULL);
    printf("the main thread finished .\n");

}

void* print_message_function(void * ptr) {
    int j = 0 ;
    for(int i = 0; i < 10; i ++) {
        total++;
        sleep(4);
        printf("pid=%d,tid=%d\n",getpid(), pthread_self());
        j ++;
    }
    printf("the print_message_function finished .\n");
}
