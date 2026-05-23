#include <stdio.h>
#include <pthread.h>
#include <unistd.h>


void* printText(void* seconds);

int main() {
    
    int s1 = 10, s2 = 15;
    pthread_t thread1;
    pthread_t thread2;
    
    pthread_create(&thread1, NULL, (void* (*)(void*))&printText, (void*)&s1);
    pthread_create(&thread2, NULL, (void* (*)(void*))&printText, (void*)&s2);
    

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    return 0;
}

void* printText(void* seconds) {
    int secs = *(int*)seconds;    //copy value
    for (int i = 1; i <= secs; i++) {
        printf("i= %d\n", i);
        sleep(1);
    }

}