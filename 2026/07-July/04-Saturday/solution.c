#include <limits.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Edge {
    int to;
    int dist;
    struct Edge* next;
} Edge;

void addEdge(Edge** graph, int u, int v, int d) {
    Edge* e = (Edge*)malloc(sizeof(Edge));
    e->to = v;
    e->dist = d;
    e->next = graph[u];
    graph[u] = e;
}

int minScore(int n, int** roads, int roadsSize, int* roadsColSize) {
    Edge** graph = (Edge**)calloc(n + 1, sizeof(Edge*));

    for (int i = 0; i < roadsSize; i++) {
        int u = roads[i][0];
        int v = roads[i][1];
        int d = roads[i][2];
        addEdge(graph, u, v, d);
        addEdge(graph, v, u, d);
    }

    bool* vis = (bool*)calloc(n + 1, sizeof(bool));
    int* queue = (int*)malloc((n + 1) * sizeof(int));
    int front = 0, rear = 0;

    queue[rear++] = 1;
    vis[1] = true;

    int ans = INT_MAX;

    while (front < rear) {
        int node = queue[front++];

        for (Edge* cur = graph[node]; cur != NULL; cur = cur->next) {
            if (cur->dist < ans)
                ans = cur->dist;

            if (!vis[cur->to]) {
                vis[cur->to] = true;
                queue[rear++] = cur->to;
            }
        }
    }

    return ans;
}
