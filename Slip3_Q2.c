#include <stdio.h>
#define MAX 20
#define INF 999

void prims(int arr[MAX][MAX], int limit) {
    int visit[MAX] = {0};
    int mincost = 0;
    int e, u = 0, v = 0, i, j, min;

    visit[0] = 1;
    printf("\nEdges in the Minimum Spanning Tree:\n");
    for (e = 0; e < limit - 1; e++) {
        min = INF;

        for (i = 0; i < limit; i++) {
            if (visit[i]) {
                for (j = 0; j < limit; j++) {
                    if (!visit[j] && arr[i][j] < min) {
                        min = arr[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        visit[v] = 1;
        printf("Edge: %d - %d | Cost: %d\n", u + 1, v + 1, min);
        mincost += min;

        arr[u][v] = arr[v][u] = INF;
    }

    printf("\nMinimum Cost of MST = %d\n", mincost);
}

int main() {
    int arr[MAX][MAX], limit, i, j;

    printf("ENTER LIMIT: ");
    scanf("%d", &limit);

    printf("Enter the adjacency matrix:\n");
    for (i = 0; i < limit; i++) {
        for (j = 0; j < limit; j++) {
            scanf("%d", &arr[i][j]);
            if (arr[i][j] == 0)
                arr[i][j] = INF;
        }
    }

    prims(arr, limit);
    return 0;
}
/*
      0 20 0 0 0 4 0
      20 0 8 0 0 0 7
      0 8 0 6 0 0 0
      0 0 6 0 10 0 9
      0 0 0 10 0 10 11
      4 0 0 0 15 0 0
      0 7 0 9 11 0 0 
*/
