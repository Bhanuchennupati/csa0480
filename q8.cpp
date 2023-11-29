#include <stdio.h>
struct Process {
    int id;
    int burst_time;
    int remaining_time;
};
void roundRobin(struct Process processes[], int n, int time_quantum) {
    int remaining_processes = n;
    int time = 0;
    while (remaining_processes > 0) {
        for (int i = 0; i < n; i++) {
            if (processes[i].remaining_time > 0) {
                int execute_time = (processes[i].remaining_time > time_quantum) ? time_quantum : processes[i].remaining_time;
                processes[i].remaining_time -= execute_time;
                time += execute_time;
                printf("Process %d executes for time %d units.\n", processes[i].id, execute_time);
                if (processes[i].remaining_time == 0) {
                    remaining_processes--;
                }
            }
        }
    }
}
int main() {
    int n, time_quantum;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    struct Process processes[n];
    printf("Enter burst time for each process:\n");
    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1;
        printf("Burst time for Process %d: ", i + 1);
        scanf("%d", &processes[i].burst_time);
        processes[i].remaining_time = processes[i].burst_time;
    }
    printf("Enter the time quantum: ");
    scanf("%d", &time_quantum);
    printf("\nRound Robin Scheduling Simulation:\n");
    roundRobin(processes, n, time_quantum);
    return 0;
}
