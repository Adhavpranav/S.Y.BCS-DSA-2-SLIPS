#include <stdio.h>

#define INF 999
int i, j, n;

void dijkstra(int a[10][10]) {
    int d[20], visit[20] = {0};
    int min, v = 0;

    // Initialize distances
    for (i = 0; i < n; i++) {
        d[i] = a[0][i];  // Distance from source (0) to i
        visit[i] = 0;     // None visited yet
    }

    d[0] = 0;
    visit[0] = 1;

    for (int count = 1; count < n; count++) {
        min = INF;
        
        // Find the minimum distance unvisited node
        for (i = 0; i < n; i++) {
            if (!visit[i] && d[i] < min) {
                min = d[i];
                v = i;
            }
        }

        visit[v] = 1;

        // Update distances of neighbors of v
        for (i = 0; i < n; i++) {
            if (!visit[i] && d[v] + a[v][i] < d[i]) {
                d[i] = d[v] + a[v][i];
            }
        }
    }

    // Output
    printf("\nDijkstra’s Shortest Path from Vertex 1:\n");
    for (i = 0; i < n; i++) {
        printf("To V%d: %d\n", i + 1, d[i]);
    }
}

int main() {
    int a[10][10];
    printf("Enter vertex limit: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix (0 if no edge):\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
            if (a[i][j] == 0 && i != j)
                a[i][j] = INF;  // Replace 0 with INF
        }
    }

    dijkstra(a);
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
