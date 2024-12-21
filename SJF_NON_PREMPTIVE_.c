#include <stdio.h>

void findWaitingTime(int n, int bt[], int wt[], int at[], int ct[]) {
    wt[0] = 0; // First process has no waiting time
    for (int i = 1; i < n; i++) {
        wt[i] = ct[i - 1] - at[i];
        if (wt[i] < 0) {
            wt[i] = 0;
        }
    }
}

void findTurnAroundTime(int n, int bt[], int wt[], int tat[], int ct[]) {
    for (int i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
    }
}

void findCompletionTime(int n, int bt[], int at[], int ct[]) {
    ct[0] = bt[0] + at[0]; // First process completion time
    for (int i = 1; i < n; i++) {
        ct[i] = ct[i - 1] + bt[i];
    }
}

void sortByBurstTime(int n, int pid[], int bt[], int at[]) {
    int temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (bt[i] > bt[j]) {
                // Swap burst time
                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;

                // Swap arrival time
                temp = at[i];
                at[i] = at[j];
                at[j] = temp;

                // Swap process IDs
                temp = pid[i];
                pid[i] = pid[j];
                pid[j] = temp;
            }
        }
    }
}

void printProcesses(int n, int pid[], int bt[], int at[], int wt[], int tat[], int ct[]) {
    printf("\nProcess ID\tBurst Time\tArrival Time\tWaiting Time\tTurn Around Time\tCompletion Time\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t\t%d\n", pid[i], bt[i], at[i], wt[i], tat[i], ct[i]);
    }
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int pid[n], bt[n], at[n], wt[n], tat[n], ct[n];

    for (int i = 0; i < n; i++) {
        printf("Enter the burst time and arrival time for process %d: ", i + 1);
        scanf("%d %d", &bt[i], &at[i]);
        pid[i] = i + 1;  // Assign process IDs
    }

    // Sort processes by burst time
    sortByBurstTime(n, pid, bt, at);

    // Calculate completion time
    findCompletionTime(n, bt, at, ct);

    // Calculate waiting time
    findWaitingTime(n, bt, wt, at, ct);

    // Calculate turnaround time
    findTurnAroundTime(n, bt, wt, tat, ct);

    // Print process details
    printProcesses(n, pid, bt, at, wt, tat, ct);

    return 0;
}
