#include<stdio.h>
void swap(int *i,int *j)
{
    int temp=*i;
    *i=*j;
    *j=temp;
}
int main()
{
	int i, k, n;
	printf("Enter the number of processes:");
	scanf("%d",&n);
	int pid[n],bt[n], su[n], wt[n],tat[n];
	for(i=0;i<n;i++)
	{
		pid[i] = i;
		printf("Enter the Burst Time of Process%d:", i);
		scanf("%d",&bt[i]);
		printf("System/User Process (0/1) ? ");
		scanf("%d", &su[i]);
	}
	for(i=0;i<n;i++)
		for(k=i+1;k<n;k++)
			if(su[i] > su[k])
			{
			swap(&pid[i],&pid[k]);
			swap(&bt[i],&bt[k]);
			swap(&su[i],&su[k]);
			}
	float wtTotal= wt[0] = 0;
	float tatTotal= tat[0] = bt[0];
	for(i=1;i<n;i++)
	{
		wt[i] = wt[i-1] + bt[i-1];
		tat[i] = tat[i-1] + bt[i];
		wtTotal = wtTotal + wt[i];
		tatTotal = tatTotal + tat[i];
	}
	printf("\nPROCESS\t\t SYSTEM/USER PROCESS \tBURST TIME\tWAITING TIME\tTURNAROUND TIME");
	for(i=0;i<n;i++)
		printf("\n%d \t\t %d \t\t %d \t\t %d \t\t %d ",pid[i],su[i],bt[i],wt[i],tat[i]);
	printf("\nAverage Waiting Time is --- %f",wtTotal/n);
	printf("\nAverage Turnaround Time is --- %f",tatTotal/n);
	return 0;
}
