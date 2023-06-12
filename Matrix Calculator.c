#include <stdio.h>
#include <stdlib.h>

struct matrix
{
    int m, n;
    int **a;
};
typedef struct matrix mat;

void add(mat m1, mat m2)
{
    if (m1.m == m2.m && m1.n == m2.n)
    {
        printf("The sum matrix would be:\n");
        int i, j;
        for (i = 0; i < m1.m; i++)
        {
            for (j = 0; j < m1.n; j++)
            {
                m1.a[i][j] += m2.a[i][j];
                printf("%d\t", m1.a[i][j]);
            }
            printf("\n");
        }
    }
    else
    {
        printf("The matrices cannot be added!");
    }
}

void sub(mat m1, mat m2)
{
    if (m1.m == m2.m && m1.n == m2.n)
    {
        printf("The difference matrix would be:\n");
        int i, j;
        for (i = 0; i < m1.m; i++)
        {
            for (j = 0; j < m1.n; j++)
            {
                m1.a[i][j] -= m2.a[i][j];
                printf("%d\t", m1.a[i][j]);
            }
            printf("\n");
        }
    }
    else
    {
        printf("The matrices cannot be subtracted!");
    }
}

void transpose(mat a)
{
    printf("The transposed matrix would be:\n");
    int i, j;
    for (i = 0; i < a.n; i++)
    {
        for (j = 0; j < a.m; j++)
        {
            printf("%d\t", a.a[j][i]);
        }
        printf("\n");
    }
}

void multiply(mat m1, mat m2)
{
    if (m1.n == m2.m)
    {
        int m3[m1.m][m2.n];
        int i, j, k;
        for (int i = 0; i < m1.m; ++i)
        {
            for (int j = 0; j < m2.n; ++j)
            {
                m3[i][j] = 0;
            }
        }
        printf("The multiplied matrix would be:\n");
        for (int i = 0; i < m1.m; ++i)
        {
            for (int j = 0; j < m2.n; ++j)
            {
                for (int k = 0; k < m1.n; ++k)
                {
                    m3[i][j] += (m1.a[i][k]) * (m2.a[k][j]);
                }
                printf("%d\t", m3[i][j]);
            }
            printf("\n");
        }
    }
    else
    {
        printf("These matrices cannot be multiplied!");
    }
}

int main()
{
    printf("Enter the order of first matrix: ");
    mat a;
    int i, j;
    scanf("%d%d", &a.m, &a.n);
    a.a = (int **)malloc(a.m * sizeof(int *));
    for (i = 0; i < a.m; i++)
    {
        a.a[i] = (int *)malloc(a.n * sizeof(int));
    }
    printf("Enter %d elements into the first matrix: ", a.m * a.n);
    for (i = 0; i < a.m; i++)
    {
        for (j = 0; j < a.n; j++)
        {
            scanf("%d", &a.a[i][j]);
        }
    }

    printf("Enter the order of second matrix: ");
    mat b;
    scanf("%d%d", &b.m, &b.n);
    b.a = (int **)malloc(b.m * sizeof(int *));
    for (i = 0; i < b.m; i++)
    {
        b.a[i] = (int *)malloc(b.n * sizeof(int));
    }
    printf("Enter %d elements into the second matrix: ", b.m * b.n);
    for (i = 0; i < b.m; i++)
    {
        for (j = 0; j < b.n; j++)
        {
            scanf("%d", &b.a[i][j]);
        }
    }

    while (1)
    {
        printf("\n\nMenu\n1) Addition\n2) Subtraction\n3) Transpose\n4) Multiply\nYour choice: ");
        int choice;
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            add(a, b);
            break;
        case 2:
            sub(a, b);
            break;
        case 3:
            printf("Which matrix do you want to transpose(matrix 1 or 2): ");
            int c1;
            scanf("%d", &c1);
            if (c1 == 1)
                transpose(a);
            else if (c1 == 2)
                transpose(b);
            else
                printf("invalid choice!");
            break;
        case 4:
            multiply(a, b);
            break;
        default:
            exit(0);
        }
    }

    return 0;
}
