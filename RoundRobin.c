#include <stdio.h>

int main()
{
    int i, wt = 0, tat = 0, n, quant, sum = 0, count = 0;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    int y = n, at[n], bt[n], temp[n];
    for (i = 0; i < n; i++)
    {
        printf("\n Enter the Arrival and Burst time of the Process[%d]: ", i + 1);
        scanf("%d", &at[i]);
        scanf("%d", &bt[i]);
        temp[i] = bt[i];
    }

    printf("Enter the time quantum for the process: \t");
    scanf("%d", &quant);

    printf("\n Process No \t\t Burst Time \t\t TAT \t\t Waiting Time ");
    for (sum = 0, i = 0; y != 0;)
    {
        // condition 1
        if (temp[i] <= quant && temp[i] > 0)
        {
            sum = sum + temp[i];
            temp[i] = 0;
            count = 1;
        }
        else if (temp[i] > 0)
        {
            temp[i] = temp[i] - quant;
            sum = sum + quant;
        }

        // condition 2
        if (temp[i] == 0 && count == 1)
        {
            y--;
            printf("\nProcess No[%d] \t\t %d\t\t\t %d\t\t\t %d", i + 1, bt[i], sum - at[i], sum - at[i] - bt[i]);
            wt = wt + sum - at[i] - bt[i];
            tat = tat + sum - at[i];
            count = 0;
        }

        // condition 3
        if (at[i + 1] <= sum)
        {
            i++;
        }
        else
        {
            i = 0;
        }
    }

    float avg_wt, avg_tat;
    avg_wt = wt * 1.0 / n;
    avg_tat = tat * 1.0 / n;
    printf("\n Average Turn Around Time: \t%f", avg_wt);
    printf("\n Average Waiting Time: \t%f\n", avg_tat);

    return 0;
}
