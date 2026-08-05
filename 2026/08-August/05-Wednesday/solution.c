/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int val;
    struct Node* next;
} Node;

void addEdge(Node** graph, int u, int v) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->val = v;
    node->next = graph[u];
    graph[u] = node;
}

void dfs(Node** graph, bool* suspicious, int u) {
    suspicious[u] = true;
    for (Node* cur = graph[u]; cur; cur = cur->next) {
        if (!suspicious[cur->val]) {
            dfs(graph, suspicious, cur->val);
        }
    }
}

void dfs2(Node** graph, bool* suspicious, bool* visited, int u) {
    visited[u] = true;
    for (Node* cur = graph[u]; cur; cur = cur->next) {
        if (!visited[cur->val]) {
            suspicious[cur->val] = false;
            dfs2(graph, suspicious, visited, cur->val);
        }
    }
}

int* remainingMethods(int n, int k, int** invocations, int invocationsSize,
                      int* invocationsColSize, int* returnSize) {

    Node** graph = (Node**)calloc(n, sizeof(Node*));
    Node** undirected = (Node**)calloc(n, sizeof(Node*));

    for (int i = 0; i < invocationsSize; i++) {
        int u = invocations[i][0];
        int v = invocations[i][1];

        addEdge(graph, u, v);

        addEdge(undirected, u, v);
        addEdge(undirected, v, u);
    }

    bool* suspicious = (bool*)calloc(n, sizeof(bool));
    bool* visited = (bool*)calloc(n, sizeof(bool));

    dfs(graph, suspicious, k);

    for (int i = 0; i < n; i++) {
        if (!suspicious[i] && !visited[i]) {
            dfs2(undirected, suspicious, visited, i);
        }
    }

    int* ans = (int*)malloc(sizeof(int) * n);
    *returnSize = 0;

    for (int i = 0; i < n; i++) {
        if (!suspicious[i]) {
            ans[(*returnSize)++] = i;
        }
    }

    return ans;
}
