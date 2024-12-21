#include<stdio.h>
int main(int argc, char const *argv[])
{
    int n, a[10],bt[10],ct[10],wt[10],tat[10],sum,i,j,k;
    float avgwt=0,avgtat=0;

    printf("Enter the total number of process ");
    scanf("%d",&n);
    
    printf("\nEnter the process Arrival time and Brust time\n");
    for(i=0;i<n;i++)
    {
        printf("\nEnter the arrival time of process %d ",i+1);
        scanf("%d",&a[i]);

        printf("\nEnter the brust time of process %d ",i+1);
        scanf("%d",&bt[i]);
    }

    // Calculate completion time of process
    sum=a[0];
    for(i=0;i<n;i++)
    {   
        sum=sum+bt[i];
        ct[i]=sum;
    }

    // Calculate Turn Around Time of process
    for(i=0;i<n;i++)
    {
        tat[i]=ct[i]-a[i];
        avgtat=avgtat+tat[i];
    }

    //calculate Waiting Time of process
    for(i=0;i<n;i++)
    {
        wt[i]=tat[i]-bt[i];
        avgwt=avgwt+wt[i];
    }

    printf("\n*****OUTPUT*****");
    printf("\nPr\tAT\tBT\tCT\tTAT\tWT\n");
    for(i=0;i<n;i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",i,a[i],bt[i],ct[i],tat[i],wt[i]);
    }
    return 0;
}
