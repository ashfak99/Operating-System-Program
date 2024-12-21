#include <stdio.h>
void priorityScheduling(int n, int pid[], int arrivalTime[], int burstTime[], int priority[]) {
    int remainingTime[n];
    int completionTime[n], waitingTime[n], turnAroundTime[n];
    int isCompleted[n]; // Array to check if the process is completed
    int currentTime = 0, completed = 0;
    int totalWaitingTime = 0, totalTurnAroundTime = 0;
    for (int i = 0; i < n; i++) {
        remainingTime[i] = burstTime[i];
        isCompleted[i] = 0;
    }
    while (completed != n) {
        int idx = -1;       
        int highestPriority = 9999;
        for (int i = 0; i < n; i++) {
            if (arrivalTime[i] <= currentTime && !isCompleted[i]) {
                if (priority[i] < highestPriority || (priority[i] == highestPriority && arrivalTime[i] < arrivalTime[idx])) {
                    highestPriority = priority[i];
                    idx = i;
                }
            }
        }
        if (idx != -1) {
            remainingTime[idx]--;
            currentTime++;
            if (remainingTime[idx] == 0) {
                completionTime[idx] = currentTime;
                turnAroundTime[idx] = completionTime[idx] - arrivalTime[idx];
                waitingTime[idx] = turnAroundTime[idx] - burstTime[idx];               
                totalWaitingTime += waitingTime[idx];
                totalTurnAroundTime += turnAroundTime[idx];     
                isCompleted[idx] = 1;
                completed++;
            }
        } else {
            currentTime++;
        }
    }
    printf("\nPID\tArrival Time\tBurst Time\tPriority\tCompletion Time\tTurnaround Time\tWaiting Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", 
               pid[i], arrivalTime[i], burstTime[i], priority[i],
               completionTime[i], turnAroundTime[i], waitingTime[i]);
    }
    printf("\nAverage Turnaround Time: %.2f", (float)totalTurnAroundTime / n);
    printf("\nAverage Waiting Time: %.2f\n", (float)totalWaitingTime / n);
}
int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    int pid[n], arrivalTime[n], burstTime[n], priority[n];
    for (int i = 0; i < n; i++) {
        pid[i] = i + 1;
        printf("\nEnter details for process %d\n", pid[i]);
        printf("Arrival Time: ");
        scanf("%d", &arrivalTime[i]);
        printf("Burst Time: ");
        scanf("%d", &burstTime[i]);
        printf("Priority (lower number = higher priority): ");
        scanf("%d", &priority[i]);
    }
    priorityScheduling(n, pid, arrivalTime, burstTime, priority);
    return 0;
}