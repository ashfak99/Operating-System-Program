#include<stdio.h>
void findwt(int n, int a[], int b[], int c[], int t[], int w[])
{
    w[0]=0;
    for (int i = 1; i < n; i++)
    {
        w[i]=c[i-1]-a[i];
        if (w[i]<0)
        {
            w[i]=0;
        }
    } 
}

void findtat(int n, int a[], int b[], int c[], int t[], int w[])
{
    for (int i = 0; i < n; i++)
    {
        t[i]=c[i]-a[i];
    }
}

void findct(int n, int a[], int b[], int c[], int t[], int w[])
{
    c[0]=b[0]+a[0];
    for (int i = 1; i < n; i++)
    {
        c[i]=c[i-1]+b[i];
    }
}

void sortByBurstTie(int n, int pid[], int a[], int b[])
{
    int temp;
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if (b[i]>b[j])
            {
                temp = b[i];
                b[i] = b[j];
                b[j] = temp;

                temp = a[i];
                a[i] = a[j];
                a[j] = temp;

                temp = pid[i];
                pid[i] = pid[j];
                pid[j] = temp;
            }
        }  
    }
}

void printProcesses(int n, int pid[], int a[], int b[], int c[], int t[], int w[])
{
    printf("\nProcess ID \t AT\t BT\t CT\t TT\t WT\n");
    for (int i = 0; i < n; i++)
    {
        printf("P%d\t\t%d\t%d\t%d\t%d\t%d\n",pid[i],a[i],b[i],c[i],t[i],w[i]);
    }
}

int main(int argc, char const *argv[])
{
    int n;
    printf("Enter the Number of Process : ");
    scanf("%d",&n);
    
    int pid[n], at[n], bt[n], ct[n], tat[n], wt[n];

    for (int i = 0; i < n; i++)
    {
        printf("Enter Arrival Time of Process %d : ",i);
        scanf("%d",&at[i]);
        printf("Enter Burst Time of Process %d : ",i);
        scanf("%d",&bt[i]);
        pid[i]=i+1;
    }
    
    sortByBurstTie(n,pid,at,bt);

    findct(n,at,bt,ct,tat,wt);

    findtat(n,at,bt,ct,tat,wt);

    findwt(n,at,bt,ct,tat,wt);

    printProcesses(n,pid,at,bt,ct,tat,wt);

    return 0;
}