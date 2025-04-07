#include <stdio.h>

#define INF 999

void printMatrix(int a[10][10], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++) 
        {
            if (a[i][j] == INF)
                printf("%4s", "INF");
            else
                printf("%4d", a[i][j]);
        }
        printf("\n");
    }
}

void floydWarshall(int a[10][10], int n)
{
    for (int k = 0; k < n; k++) 
    {
        for (int i = 0; i < n; i++) 
        {
            for (int j = 0; j < n; j++) 
            {
                if (a[i][k] != INF && a[k][j] != INF && a[i][k] + a[k][j] < a[i][j])
                {
                    a[i][j] = a[i][k] + a[k][j];
                }
            }
        }
        printf("\nd(%d):\n", k + 1);
        printMatrix(a, n);
    }
}

int main() 
{
    int a[10][10], n;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix (use 999 for infinity):\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    floydWarshall(a, n);

    return 0;
}
/*
0   5   999 10
999 0   3   999
999 999 0   1
999 999 999 0
*/
