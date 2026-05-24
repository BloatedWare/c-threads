#include <stdio.h>
#include <pthread.h>

int counter = 0;
pthread_mutex_t myLock = PTHREAD_MUTEX_INITIALIZER;

void *thread_entry(void *arg);

int main() {
    pthread_t thread1, thread2;
    int th1_max = 1000000;
    int th2_max = 2000000;
    int *th1_ret, *th2_ret;

    pthread_create(&thread1, NULL, (void* (*)(void*))thread_entry, (void*)&th1_max);
    pthread_create(&thread2, NULL, (void* (*)(void*))thread_entry, (void*)&th2_max);
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    // for (int i = 0; i < th1_max; i++) {
    //     counter++;
    // }
    // for (int i = 0; i < th2_max; i++) {
    //     counter++;
    // }
    printf("counter= %d\n", counter);
    return 0;
}

void *thread_entry(void *arg) {
    //args will be a pointer to an int

    int max_count = *(int*)arg;
    pthread_mutex_lock(&myLock);
    for (int i = 0; i < max_count; i++) {
        counter++;
    }
    pthread_mutex_unlock(&myLock);
    return NULL;//now this no longer undefined behavior   
}