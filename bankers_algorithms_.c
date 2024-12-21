#include <stdio.h>

int main() {
    int n, m;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter the number of resource types: ");
    scanf("%d", &m);

    int allocation[n][m]; 
    int max[n][m];        
    int available[m];    
    int need[n][m];      
    int safeSequence[n]; 
    int finished[n];      

    for (int i = 0; i < n; i++)
        finished[i] = 0;
    printf("Enter the allocation matrix:\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d allocation: ", i);
        for (int j = 0; j < m; j++) {
            scanf("%d", &allocation[i][j]);
        }
    }
    printf("Enter the maximum matrix:\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d maximum: ", i);
        for (int j = 0; j < m; j++) {
            scanf("%d", &max[i][j]);
        }
    }
    printf("Enter the available resources: ");
    for (int j = 0; j < m; j++) {
        scanf("%d", &available[j]);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }
    int count = 0;
    while (count < n) {
        int found = 0;
        for (int i = 0; i < n; i++) {
            if (!finished[i]) { 
                int canProceed = 1;
                for (int j = 0; j < m; j++) {
                    if (need[i][j] > available[j]) {
                        canProceed = 0;
                        break;
                    }
                }
                if (canProceed) {
                    for (int j = 0; j < m; j++) {
                        available[j] += allocation[i][j];
                    }
                    safeSequence[count++] = i; 
                    finished[i] = 1;
                    found = 1;
                }
            }
        }
        if (!found) {
            printf("System is not in a safe state.\n");
            return 0;
        }
    }
    printf("System is in a safe state.\nSafe sequence is: ");
    for (int i = 0; i < n; i++) {
        printf("P%d ", safeSequence[i]);
    }
    printf("\n");
    return 0;
}