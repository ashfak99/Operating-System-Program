#include <stdio.h>

void calculateTimes(int n, int burstTime[], int arrivalTime[], int priority[], int completionTime[], int waitingTime[], int turnAroundTime[]) {
    int time = 0;
    for (int i = 0; i < n; i++) {
        time += burstTime[i];
        completionTime[i] = time;
        turnAroundTime[i] = completionTime[i] - arrivalTime[i];
        waitingTime[i] = turnAroundTime[i] - burstTime[i];
    }
}

void sortByPriority(int n, int pid[], int arrivalTime[], int burstTime[], int priority[]) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (priority[i] > priority[j] || 
               (priority[i] == priority[j] && arrivalTime[i] > arrivalTime[j])) {
                int temp;
                temp = pid[i];
                pid[i] = pid[j];
                pid[j] = temp;
                temp = arrivalTime[i];
                arrivalTime[i] = arrivalTime[j];
                arrivalTime[j] = temp;
                temp = burstTime[i];
                burstTime[i] = burstTime[j];
                burstTime[j] = temp;
                temp = priority[i];
                priority[i] = priority[j];
                priority[j] = temp;
            }
        }
    }
}
void printTable(int n, int pid[], int arrivalTime[], int burstTime[], int priority[], int completionTime[], int turnAroundTime[], int waitingTime[]) {
    printf("\nPID\tArrival Time\tBurst Time\tPriority\tCompletion Time\tTurnaround Time\tWaiting Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", 
               pid[i], arrivalTime[i], burstTime[i], priority[i],
               completionTime[i], turnAroundTime[i], waitingTime[i]);
    }
}
void calculateAverageTimes(int n, int turnAroundTime[], int waitingTime[]) {
    float totalTurnAroundTime = 0, totalWaitingTime = 0;
    for (int i = 0; i < n; i++) {
        totalTurnAroundTime += turnAroundTime[i];
        totalWaitingTime += waitingTime[i];
    }
    printf("\nAverage Turnaround Time: %.2f", totalTurnAroundTime / n);
    printf("\nAverage Waiting Time: %.2f\n", totalWaitingTime / n);
}
int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    int pid[n], arrivalTime[n], burstTime[n], priority[n];
    int completionTime[n], waitingTime[n], turnAroundTime[n];
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
    sortByPriority(n, pid, arrivalTime, burstTime, priority);
    calculateTimes(n, burstTime, arrivalTime, priority, completionTime, waitingTime, turnAroundTime);
    printTable(n, pid, arrivalTime, burstTime, priority, completionTime, turnAroundTime, waitingTime);
    calculateAverageTimes(n, turnAroundTime, waitingTime);
    return 0;
}