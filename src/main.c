#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

void* printText(void* seconds);

int main() {
    void *my_thing = NULL, *my_thing2 = NULL;
    int s1 = 5, s2 = 8;
    pthread_t thread1;
    pthread_t thread2;
    
    pthread_create(&thread1, NULL, (void* (*)(void*))&printText, (void*)&s1);
    sleep(3);
    pthread_create(&thread2, NULL, (void* (*)(void*))&printText, (void*)&s2);
    

    pthread_join(thread1, &my_thing);
    printf("thread1 returned %p and i will read it as (int) because i can :p\nmy thing = %d\n",my_thing, *(int*)my_thing);
    pthread_join(thread2, &my_thing2);
    printf("thread2 returned %p and i will read it as (int) because i can :p\nmy thing 2= %d\n",my_thing, *(int*)my_thing2);
    free(my_thing);
    free(my_thing2);
    return 0;
}

void* printText(void* seconds) {
    int secs = *(int*)seconds;    //copy value
    int *someHeapAddress;
    for (int i = 1; i <= secs; i++) {
        printf("i= %d\n", i);
        sleep(1);
    }
    someHeapAddress = (int*)malloc(sizeof(int));
    if(someHeapAddress == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    *someHeapAddress = secs;
}
