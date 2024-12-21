#include<stdio.h>
void sortByArrivalandPriority(int n,int pid[], int at[], int bt[], int prt[])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if (at[i]>at[j] || (prt[i] > prt[j] && at[i]==at[j]))
            {
                int temp;
                temp=at[i];
                at[i]=at[j];
                at[j]=temp;

                temp=bt[i];
                bt[i]=bt[j];
                bt[j]=temp;

                temp=pid[i];
                pid[i]=pid[j];
                pid[j]=temp;

                temp=prt[i];
                prt[i]=prt[j];
                prt[j]=temp;
            }
        }
    }
}

void findwtandtat(int n, int quantam, int at[], int bt[], int wt[], int ct[], int tat[])
{
    int t=0;
    int done;
    int obt[10];

    for (int i = 0; i < n; i++)
    {
        obt[i]=bt[i];
    }
    
    while (1)
    {
        done=1;
        for (int i = 0; i < n; i++)
        {
            if (bt[i]>0 && at[i]<=t)
            {
                done=0;
                if (bt[i]>quantam)
                {
                    bt[i]=bt[i]-quantam;
                }
                else{
                    t+=bt[i];
                    bt[i]=0;
                    wt[i]=t-at[i]-obt[i];
                    if (wt[i]<0)
                        wt[i]=0;
                    ct[i]=t;
                }
            }
        }
        if (done==1)
        t++;
        break;
    }
    for (int i = 0; i < n; i++)
    {
        tat[i]=ct[i]-at[i];
    }
}

void print(int n,int PID[], int at[], int bt[], int ct[], int pt[], int tat[], int wt[])
{
    printf("\nPID\tAT\tBT\tCT\tPT\tTAT\tWT\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",PID[i],at[i],bt[i],ct[i],pt[i],tat[i],wt[i]);
    }
}
int main(int argc, char const *argv[])
{
    int n,at[10],bt[10],ct[10],wt[10],tat[10],p[10],pid[10],quantam;
    printf("Enter the Number of Process : ");
    scanf("%d",&n);

    for (int i = 0; i < n; i++)
    {
        printf("\nEnter Arrival time of Process %d : ",i);
        scanf("%d",&at[i]);
        printf("\nEnter Burst time of Process %d : ",i);
        scanf("%d",&bt[i]);
        printf("\nEnter Priority of Process %d : ",i);
        scanf("%d",&p[i]);
        pid[i]=i+1;
    }

    printf("\nEnter The Time Quantam : ");
    scanf("%d",&quantam);

    sortByArrivalandPriority(n,pid,at,bt,p);

    findwtandtat(n,quantam,at,bt,wt,ct,tat);

    print(n,pid,at,bt,ct,p,tat,wt);
    return 0;
}
