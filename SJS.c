#include <stdio.h>
#include <stdlib.h>

struct process
{
    float bt, wt, tt;
    int id;
};

int main()
{
    int n, i, j;
    float waitingTime, turnAroundTime;

    printf("Enter the number of processes: ");
    scanf("%d", &n);
    struct process *p = (struct process *)malloc(n * sizeof(struct process));

    printf("Enter the burst times of %d processes: ", n);
    for (i = 0; i < n; i++)
    {
        scanf("%f", &p[i].bt);
        p[i].id = i + 1;
    }

    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (p[i].bt > p[j].bt)
            {
                struct process temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    for (i = 0; i < n; i++)
    {
        if (i == 0)
        {
            p[i].wt = 0;
        }
        else
        {
            p[i].wt = p[i - 1].bt + p[i - 1].wt;
        }
        p[i].tt = p[i].bt + p[i].wt;
        waitingTime += p[i].wt;
        turnAroundTime += p[i].tt;
    }

    printf("\nThe details of the processes are as below:\nProcess\tBurst Time\tTurn Around Time\tWaiting Time\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t%f\t%f\t%f\n", p[i].id, p[i].bt, p[i].tt, p[i].wt);
    }

    printf("The average waiting time is: %f", waitingTime / (float)n);
    printf("\nThe average turn around time is: %f", turnAroundTime / n);
    return 0;
}
