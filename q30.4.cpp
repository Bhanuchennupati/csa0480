#include <stdio.h>
#include <pthread.h>
void *printMessage(void *arg) {
    char *message = (char *)arg;
    printf("%s\n", message);
    pthread_exit((void *)42);
}
int main() {
    pthread_t tid;
    char *message = "Hello, Thread!";
    if (pthread_create(&tid, NULL, printMessage, (void *)message) != 0) {
        fprintf(stderr, "Error creating thread\n");
        return 1;
    }
    void *status;
    pthread_join(tid, &status);
    printf("Thread exited with status: %ld\n", (long)status);
    return 0;
}

