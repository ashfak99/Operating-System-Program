#include <stdio.h>

#define MAX 100

int n;                  // Number of processes
int at[MAX];            // Arrival time
int bt[MAX];            // Burst time
int pr[MAX];            // Priority
int wt[MAX];            // Waiting time
int tat[MAX];           // Turnaround time
int ct[MAX];            // Completion time
int rem_bt[MAX];        // Remaining burst time
int pid[MAX];           // Process IDs

// Function to sort processes by arrival time and priority
void sortByArrivalAndPriority() {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (at[i] > at[j] || (at[i] == at[j] && pr[i] > pr[j])) {
                // Swap Arrival Time
                int temp = at[i];
                at[i] = at[j];
                at[j] = temp;
                
                // Swap Burst Time
                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;
                
                // Swap Priority
                temp = pr[i];
                pr[i] = pr[j];
                pr[j] = temp;
                
                // Swap Process ID
                temp = pid[i];
                pid[i] = pid[j];
                pid[j] = temp;
            }
        }
    }
}

// Function to calculate waiting time and turnaround time using Round Robin with Priority
void findWaitingAndTurnAroundTime(int quantum) {
    int t = 0;  // Current time
    int done;   // Flag to check if all processes are done

    // Keep executing until all processes are done
    while (1) {
        done = 1;

        // Traverse all processes
        for (int i = 0; i < n; i++) {
            if (rem_bt[i] > 0 && at[i] <= t) {
                done = 0;  // There is a pending process

                // Process execution based on time quantum
                if (rem_bt[i] > quantum) {
                    t += quantum;
                    rem_bt[i] -= quantum;
                } else {
                    t += rem_bt[i];
                    rem_bt[i] = 0;
                    wt[i] = t - bt[i] - at[i];
                    if (wt[i] < 0) wt[i] = 0;
                    ct[i] = t;
                }
            }
        }

        if (done == 1) break;  // All processes are finished
    }

    // Calculate turnaround time
    for (int i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
    }
}

// Function to display results
void printResults() {
    printf("\nPID\tArrival Time\tBurst Time\tPriority\tWaiting Time\tTurnaround Time\tCompletion Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", pid[i], at[i], bt[i], pr[i], wt[i], tat[i], ct[i]);
    }

    // Calculate and display averages
    int total_wt = 0, total_tat = 0;
    for (int i = 0; i < n; i++) {
        total_wt += wt[i];
        total_tat += tat[i];
    }

    printf("\nAverage Waiting Time: %.2f", (float)total_wt / n);
    printf(" | Average Turnaround Time: %.2f\n", (float)total_tat / n);
}

int main() {
    int quantum;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    // Input the arrival time, burst time, and priority of each process
    for (int i = 0; i < n; i++) {
        pid[i] = i + 1;
        printf("Enter Arrival Time, Burst Time, and Priority for Process %d: ", pid[i]);
        scanf("%d %d %d", &at[i], &bt[i], &pr[i]);
        rem_bt[i] = bt[i];  // Initialize remaining burst time
    }

    // Input the time quantum
    printf("Enter time quantum: ");
    scanf("%d", &quantum);

    // Sort processes by arrival time and priority
    sortByArrivalAndPriority();

    // Calculate waiting time and turnaround time using Round Robin
    findWaitingAndTurnAroundTime(quantum);

    // Display the results
    printResults();

    return 0;
}
