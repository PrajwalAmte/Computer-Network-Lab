#include <stdio.h>

struct node {
    int dist[20];
    int from[20];
} rt[10];

int main() {
    int dmat[20][20], n, i, j, k;

    printf("\nEnter the number of nodes: ");
    scanf("%d", &n);

    printf("\nEnter the cost matrix: \n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &dmat[i][j]);
            rt[i].dist[j] = dmat[i][j];
            rt[i].from[j] = j;
        }
    }

    // Bellman-Ford algorithm
    for( int iter = 0; iter < n - 1; iter++) {
        for(i = 0; i < n; i++) {
            for(j = 0; j < n; j++) {
                for(k = 0; k < n; k++) {
                    if (rt[i].dist[j] > rt[i].dist[k] + rt[k].dist[j]) {
                        rt[i].dist[j] = rt[i].dist[k] +rt[k].dist[j];
                        rt[i].from[j] = k;
                    }
                }
            }
        }
    }

    // Check for negative weight cycle
    for (i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            for(k = 0; k < n; k++) {
                if(rt[i].dist[j] > rt[i].dist[k] + rt[k].dist[j]) {
                    printf("Negative weight cycle detected!\n");
                    return 0;
                }
            }
        }
    }

    // Display final routing tables for each node
    for (i = 0; i < n; i++) {
        printf("\n\nRouting table for router %d: \n", i + 1);
        for(j = 0; j < n; j++) {
            printf("\tNode %d via %d Distance %d\n", j + 1, rt[i].from[j] + 1, rt[i].dist[j]);
        }
        printf("\n");
    }
    return 0;
}