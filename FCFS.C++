#include<stdio.h>
#include<conio.h>
int main(int argc, char const *argv[])
{
    int a[10],b[10],c[10],t[10],w[10];
    int n,sum,i,j;

    printf("Enter the number of process : ");
    scanf("%d",&n);

    for ( i = 0; i < n; i++)
    {
        printf("\nEnter the arrival time of Process %d : ",i+1);
        scanf("%d",&a[i]);

        printf("\nEnter the brust time of Process %d : ",i+1);
        scanf("%d",&b[i]);
    }
    
    sum=a[0];
    for ( i = 0; i < n; i++)
    {
        sum=sum+b[i];
        c[i]=sum;
    }
    
    for ( i = 0; i < n; i++)
    {
        t[i]=c[i]-a[i];        
    }
    
    for ( i = 0; i < n; i++)
    {
        w[i]=t[i]-b[i];
    }
    
    printf("\n\n*****OUTPUT*****\n\n");
    printf("Process\tAT\tBT\tCT\tTAT\tWT\n");
    for ( i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",i+1,a[i],b[i],c[i],t[i],w[i]);
    }
    
    return 0;
}
