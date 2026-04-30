/*Problem: Compute shortest path from source and detect negative weight cycles using Bellman-Ford.

Input:
- n vertices
- m edges (u,v,w)

Output:
- Shortest distances OR NEGATIVE CYCLE*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct {
    int u, v, w;
} Edge;

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    Edge *edges = (Edge *)malloc(m * sizeof(Edge));

    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
    }

    int src;
    scanf("%d", &src);

    long long *dist = (long long *)malloc(n * sizeof(long long));

    // Initialize distances
    for (int i = 0; i < n; i++)
        dist[i] = LLONG_MAX;

    dist[src] = 0;

    // Relax edges n-1 times
    for (int i = 1; i <= n - 1; i++) {
        for (int j = 0; j < m; j++) {
            int u = edges[j].u;
            int v = edges[j].v;
            int w = edges[j].w;

            if (dist[u] != LLONG_MAX && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    // Check for negative cycle
    for (int j = 0; j < m; j++) {
        int u = edges[j].u;
        int v = edges[j].v;
        int w = edges[j].w;

        if (dist[u] != LLONG_MAX && dist[u] + w < dist[v]) {
            printf("NEGATIVE CYCLE\n");
            free(edges);
            free(dist);
            return 0;
        }
    }

    // Output distances
    for (int i = 0; i < n; i++) {
        if (dist[i] == LLONG_MAX)
            printf("INF ");
        else
            printf("%lld ", dist[i]);
    }
    printf("\n");

    free(edges);
    free(dist);
    return 0;
}