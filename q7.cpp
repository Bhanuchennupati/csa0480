 #include <stdio.h>
struct Process {
    int id;
    int burst_time;
    int waiting_time;
    int turnaround_time;
};
void findWaitingTime(struct Process processes[], int n) {
    int currentTime = 0;
    processes[0].waiting_time = 0;
    for (int i = 1; i < n; i++) {
        currentTime += processes[i - 1].burst_time;
        processes[i].waiting_time = currentTime;
    }
}
void findTurnaroundTime(struct Process processes[], int n) {
    for (int i = 0; i < n; i++) {
        processes[i].turnaround_time = processes[i].waiting_time + processes[i].burst_time;
    }
}
void findAverageTime(struct Process processes[], int n) {
    int totalWaitingTime = 0, totalTurnaroundTime = 0;
    findWaitingTime(processes, n);
    findTurnaroundTime(processes, n);
    for (int i = 0; i < n; i++) {
        totalWaitingTime += processes[i].waiting_time;
        totalTurnaroundTime += processes[i].turnaround_time;
    }
    printf("Average Waiting Time: %.2f\n", (float)totalWaitingTime / n);
    printf("Average Turnaround Time: %.2f\n", (float)totalTurnaroundTime / n);
}
void sortByBurstTime(struct Process processes[], int n) {
    struct Process temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (processes[j].burst_time > processes[j + 1].burst_time) {
                temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }
}
int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    struct Process processes[n];
    printf("Enter burst time for each process:\n");
    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1;
        printf("Burst time for Process %d: ", i + 1);
        scanf("%d", &processes[i].burst_time);
    }
    sortByBurstTime(processes, n);
    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\n", processes[i].id, processes[i].burst_time, processes[i].waiting_time,
               processes[i].turnaround_time);
    }
    findAverageTime(processes, n);
    return 0;
}
