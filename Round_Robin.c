#include <stdio.h>

struct Process {
    int pid;     // Process ID
    int bt;      // Burst Time
    int at;      // Arrival Time
    int wt;      // Waiting Time
    int tat;     // Turn Around Time
    int ct;      // Completion Time
    int rem_bt;  // Remaining Burst Time
};

// Function to calculate the waiting time of all processes
void findWaitingTime(struct Process proc[], int n, int quantum) {
    int t = 0; // Current time

    // Process until all processes are done
    while (1) {
        int done = 1;

        // Traverse all processes one by one repeatedly
        for (int i = 0; i < n; i++) {
            if (proc[i].at <= t && proc[i].rem_bt > 0) {
                done = 0; // There is a pending process

                if (proc[i].rem_bt > quantum) {
                    // Increment the current time by quantum
                    t += quantum;

                    // Decrease remaining burst time by quantum
                    proc[i].rem_bt -= quantum;
                } else {
                    // If remaining burst time is smaller than or equal to quantum
                    t += proc[i].rem_bt;

                    // Waiting time is the current time minus burst time and arrival time
                    proc[i].wt = t - proc[i].bt - proc[i].at;

                    // Set remaining burst time to 0 as the process is finished
                    proc[i].rem_bt = 0;

                    // Set completion time
                    proc[i].ct = t;
                }
            }
        }

        // If all processes are done
        if (done == 1)
            break;
    }
}

// Function to calculate turnaround time
void findTurnAroundTime(struct Process proc[], int n) {
    for (int i = 0; i < n; i++) {
        proc[i].tat = proc[i].bt + proc[i].wt; // TAT = BT + WT
    }
}

// Function to find average waiting and turnaround times
void findAverageTime(struct Process proc[], int n, int quantum) {
    // Calculate waiting time of all processes
    findWaitingTime(proc, n, quantum);

    // Calculate turnaround time for all processes
    findTurnAroundTime(proc, n);

    // Display the results
    printf("Processes    Arrival time    Burst time    Waiting time    Turn around time    Completion time\n");

    int total_wt = 0, total_tat = 0;
    for (int i = 0; i < n; i++) {
        total_wt += proc[i].wt;
        total_tat += proc[i].tat;
        printf("    %d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", proc[i].pid, proc[i].at, proc[i].bt, proc[i].wt, proc[i].tat, proc[i].ct);
    }

    printf("\nAverage waiting time = %.2f", (float)total_wt / (float)n);
    printf("\nAverage turn around time = %.2f", (float)total_tat / (float)n);
}

int main() {
    // Number of processes
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process proc[n];
    
    // Input arrival time and burst time for each process
    for (int i = 0; i < n; i++) {
        proc[i].pid = i + 1;
        printf("Enter arrival time and burst time for process %d: ", proc[i].pid);
        scanf("%d %d", &proc[i].at, &proc[i].bt);
        proc[i].rem_bt = proc[i].bt; // Initially remaining burst time is equal to burst time
    }

    // Input the time quantum
    int quantum;
    printf("Enter time quantum: ");
    scanf("%d", &quantum);

    // Calculate average time using Round Robin
    findAverageTime(proc, n, quantum);

    return 0;
}
