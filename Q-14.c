#include<stdio.h>
#include<conio.h>
 int main()
{
    int bursttime[20],p[20],waitingtime[20],turnaroundtime[20],priority[20];
   int 	a,b,n,total=0,position,temp,avg_waitingtime,avg_turnaroundtime;
    printf("Enter the Total Number of Process:");
    scanf("%d",&n);
 
    printf("\nEnter Burst Time and Priority\n");
    for(a=0;a<n;a++)
    {
        printf("\nP[%d]\n",a+1);
        printf("Burst Time:");
        scanf("%d",&bursttime[a]);
        printf("Priority:");
        
        scanf("%d",&priority[a]);
        p[a]=a+1;            
    }
 
     
    for(a=0;a<n;a++)
    {
        position=a;
        for(b=a+1;b<n;b++)
        {
            if(priority[b]<priority[position])
                position=b;
        }
 
        temp=priority[a];
        priority[a]=priority[position];
        priority[position]=temp;
 
        temp=bursttime[a];
        bursttime[a]=bursttime[position];
        bursttime[position]=temp;
 
        temp=p[a];
        p[a]=p[position];
        p[position]=temp;
    }
 
    waitingtime[0]=0;     
 
    for(a=1;a<n;a++)
    {
        waitingtime[a]=0;
        for(b=0;b<a;b++)
            waitingtime[a]+=bursttime[b];
 
        total+=waitingtime[a];
    }
 
    avg_waitingtime=total/n;       
    total=0;
 
    printf("\nProcess\t    Burst Time    \tWaiting Time\tTurnaround Time");
    for(a=0;a<n;a++)
    {
        turnaroundtime[a]=bursttime[a]+waitingtime[a];      
        total+=turnaroundtime[a];
        printf("\nP[%d]\t\t  %d\t\t    %d\t\t\t%d",p[a],bursttime[a],waitingtime[a],turnaroundtime[a]);
    }
 
    avg_turnaroundtime=total/n;      
    printf("\n\nAverage Waiting Time=%d",avg_waitingtime);
    printf("\nAverage Turnaround Time=%d\n",avg_turnaroundtime);
 
    return 0;
}