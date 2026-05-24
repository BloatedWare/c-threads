#include <stdio.h>
#include <pthread.h>

int counter = 0;

void *thread_entry(void *arg);

int main() {
    pthread_t thread1, thread2;
    int th1_max = 1000000;
    int th2_max = 2000000;
    int *th1_ret, *th2_ret;

    pthread_create(&thread1, NULL, (void* (*)(void*))thread_entry, (void*)&th1_max);
    pthread_create(&thread2, NULL, (void* (*)(void*))thread_entry, (void*)&th2_max);
    pthread_join(thread1, (void*)&th1_ret);
    pthread_join(thread2, (void*)&th2_ret);
    printf("th1_ret, th2_ret values= %p, %p\n", th1_ret, th2_ret);
    printf("th1= %d, th2= %d\n", th1_max, th2_max);
    printf("counter= %d\n", counter);
    return 0;
}

void *thread_entry(void *arg) {
    //args will be a pointer to an int
    int max_count = *(int*)arg;
    for (int i = 0; i < max_count; i++) {
        counter++;
    }
    
}