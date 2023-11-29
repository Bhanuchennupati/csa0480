#include <stdio.h>
#define MAX_PROCESSES 10
struct Process {
    int process_id;
    int arrival_time;
    int burst_time;
};
void calculateWaitingTime(struct Process processes[], int n, int waiting_time[]) {
    waiting_time[0] = 0;
    for (int i = 1; i < n; i++) {
        waiting_time[i] = waiting_time[i - 1] + processes[i - 1].burst_time;
    }
}
void calculateTurnaroundTime(struct Process processes[], int n, int waiting_time[], int turnaround_time[]) {
    for (int i = 0; i < n; i++) {
        turnaround_time[i] = waiting_time[i] + processes[i].burst_time;
    }
}
void displayResults(struct Process processes[], int n, int waiting_time[], int turnaround_time[]) {
    printf("Process\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n",
               processes[i].process_id,
               processes[i].arrival_time,
               processes[i].burst_time,
               waiting_time[i],
               turnaround_time[i]);
    }
}
int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    if (n <= 0 || n > MAX_PROCESSES) {
        printf("Invalid number of processes. Exiting...\n");
        return 1;
    }
    struct Process processes[MAX_PROCESSES];
printf("Enter arrival time and burst time for each process:\n");
    for (int i = 0; i < n; i++) {
        processes[i].process_id = i + 1;
        printf("Process %d:\n", i + 1);
        printf("Arrival Time: ");
        scanf("%d", &processes[i].arrival_time);
        printf("Burst Time: ");
        scanf("%d", &processes[i].burst_time);
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (processes[j].arrival_time > processes[j + 1].arrival_time) {
                struct Process temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }
    int waiting_time[MAX_PROCESSES];
    int turnaround_time[MAX_PROCESSES];
    calculateWaitingTime(processes, n, waiting_time);
    calculateTurnaroundTime(processes, n, waiting_time, turnaround_time);
    displayResults(processes, n, waiting_time, turnaround_time);
    return 0;
}
