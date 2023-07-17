#include <stdio.h>

#define MAX_TASKS 100

typedef struct {
    int id;
    int deadline;
    int executionTime;
} Task;

void swap(Task* a, Task* b) {
    Task temp = *a;
    *a = *b;
    *b = temp;
}

void sortTasks(Task tasks[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (tasks[j].deadline > tasks[j + 1].deadline) {
                swap(&tasks[j], &tasks[j + 1]);
            }
        }
    }
}

void earliestDeadlineScheduling(Task tasks[], int n) {
    sortTasks(tasks, n);

    int currentTime = 0;
    int totalDelay = 0;

    printf("Scheduled tasks:\n");

    for (int i = 0; i < n; i++) {
        currentTime += tasks[i].executionTime;
        totalDelay += currentTime - tasks[i].deadline;

        printf("Task %d\n", tasks[i].id);
        printf("Execution Time: %d\n", tasks[i].executionTime);
        printf("Deadline: %d\n", tasks[i].deadline);
        printf("Delay: %d\n\n", currentTime - tasks[i].deadline);
    }

    printf("Total delay: %d\n", totalDelay);
}

int main() {
    Task tasks[MAX_TASKS];
    int n;

    printf("Enter the number of tasks: ");
    scanf("%d", &n);

    printf("Enter the details of each task:\n");
    for (int i = 0; i < n; i++) {
        printf("Task %d:\n", i + 1);
        printf("ID: ");
        scanf("%d", &tasks[i].id);
        printf("Deadline: ");
        scanf("%d", &tasks[i].deadline);
        printf("Execution Time: ");
        scanf("%d", &tasks[i].executionTime);
        printf("\n");
    }

    earliestDeadlineScheduling(tasks, n);

    return 0;
}
