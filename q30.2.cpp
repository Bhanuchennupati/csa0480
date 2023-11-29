#include <stdio.h>
#include <pthread.h>
void *printNumbers(void *arg) {
    int limit = *((int *)arg);
    for (int i = 1; i <= limit; ++i) {
        printf("%d\n", i);
    }
    pthread_exit(NULL);
}
int main() {
    pthread_t tid;
    int limit = 5;
    if (pthread_create(&tid, NULL, printNumbers, (void *)&limit) != 0) {
        fprintf(stderr, "Error creating thread\n");
        return 1;
    }
    pthread_join(tid, NULL);

    return 0;
}

