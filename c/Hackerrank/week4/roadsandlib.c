#include <stdio.h>
#include <stdlib.h>

long roadsAndLibraries(int n, int c_lib, int c_road, int cities_rows, int** cities) {
    if (c_lib <= c_road) return (long)n * c_lib;

    int **adj = calloc(n+1, sizeof(int*));
    int *adj_size = calloc(n+1, sizeof(int));
    for (int i = 0; i < cities_rows; i++) {
        int u = cities[i][0], v = cities[i][1];
        adj_size[u]++; adj[u] = realloc(adj[u], adj_size[u] * sizeof(int)); adj[u][adj_size[u]-1] = v;
        adj_size[v]++; adj[v] = realloc(adj[v], adj_size[v] * sizeof(int)); adj[v][adj_size[v]-1] = u;
    }

    int *visited = calloc(n+1, sizeof(int));
    int *stack = malloc((n+1) * sizeof(int));
    long total = 0;

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            int comp = 0, top = 0;
            stack[top++] = i; visited[i] = 1;
            while (top > 0) {
                int u = stack[--top]; comp++;
                for (int j = 0; j < adj_size[u]; j++) {
                    int v = adj[u][j];
                    if (!visited[v]) { visited[v] = 1; stack[top++] = v; }
                }
            }
            total += (long)c_lib + (long)(comp - 1) * c_road;
        }
    }

    for (int i = 0; i <= n; i++) free(adj[i]);
    free(adj); free(adj_size); free(visited); free(stack);
    return total;
}

int main() {
    int q;
    scanf("%d", &q);
    while (q--) {
        int n, m, c_lib, c_road;
        scanf("%d %d %d %d", &n, &m, &c_lib, &c_road);
        int **cities = malloc(m * sizeof(int*));
        for (int i = 0; i < m; i++) {
            cities[i] = malloc(2 * sizeof(int));
            scanf("%d %d", &cities[i][0], &cities[i][1]);
        }
        long result = roadsAndLibraries(n, c_lib, c_road, m, cities);
        printf("%ld\n", result);
        for (int i = 0; i < m; i++) free(cities[i]);
        free(cities);
    }
    return 0;
}
