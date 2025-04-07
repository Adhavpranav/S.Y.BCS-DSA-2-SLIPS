#include <stdio.h>

int i, j, parent[20];

// Find root of set
int find(int i) {
    while (parent[i])
        i = parent[i];
    return i;
}

// Union two sets
int uni(int i, int j) {
    if (i != j) {
        parent[j] = i;
        return 1;
    }
    return 0;
}

// Kruskal’s Algorithm
void kruskal(int a[20][20], int n) {
    int min, e = 1, u, v, b, c, mincost = 0;

    // Initialize parent array
    for (i = 0; i < n; i++)
        parent[i] = 0;

    while (e < n) {
        min = 999;

        // Find minimum cost edge
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (a[i][j] < min) {
                    min = a[i][j];
                    u = b = i;
                    v = c = j;
                }
            }
        }

        u = find(u);
        v = find(v);

        // If edge doesn't form cycle
        if (uni(u, v)) {
            printf("\nEdge %d: %d - %d  Cost: %d", e++, b + 1, c + 1, min);
            mincost += min;
        }

        // Remove this edge
        a[b][c] = a[c][b] = 999;
    }

    printf("\nMinimum Cost = %d\n", mincost);
}

int main() {
    int a[20][20], n;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix (0 if no edge):\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
            if (a[i][j] == 0)
                a[i][j] = 999;
        }
    }

    kruskal(a, n);
    return 0;
}
/*
0 2 0 6 0
2 0 3 8 5
0 3 0 0 7
6 8 0 0 9
0 5 7 9 0
*/
