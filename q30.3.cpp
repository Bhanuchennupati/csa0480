#include <stdio.h>
#include <pthread.h>
void *printMessage(void *arg) {
    printf("Thread ID: %ld\n", (long)arg);
    pthread_exit(NULL);
}
int main() {
    pthread_t tid1, tid2;
    pthread_create(&tid1, NULL, printMessage, (void *)tid1);
    pthread_create(&tid2, NULL, printMessage, (void *)tid2);
    if (pthread_equal(tid1, tid2)) {
        printf("Threads are equal.\n");
    } else {
        printf("Threads are not equal.\n");
    }
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
	    return 0;
}

