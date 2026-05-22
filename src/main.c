#include <stdio.h>
#include <pthread.h>
#include <unistd.h>


void printText(void *arg);

int main() {

    int x = 29;
    int y = 468;
    pthread_t thread1;
    pthread_t thread2;
    
    pthread_create(&thread1, NULL, (void*)&printText, (void*)&x);
    pthread_create(&thread2, NULL, (void*)&printText, (void*)&y);


    pthread_join(thread1, NULL);
    return 0;
}

void printText(void* arg) {
    static int counter = 0;
    int cast_arg = *(int*)arg;//I m creating copy
    int local_counter;
    // if(counter%2) {
    //     printf("counter == %d \n", counter);
    //     sleep(1);
    // }
    local_counter = ++counter;
    
    printf("the passed arg to function via pthread_create (before): %d\n", *(int*)arg);
    *(int*)arg *= 10;
    printf("the passed arg to function via pthread_create (after): %d\n", *(int*)arg);

    while (1) {
        printf("Hello there!%d\n", local_counter);
        sleep(1);
    }
}