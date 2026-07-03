#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>

typedef struct {
    int to;
    int w;
    int next;
} Edge;

typedef struct {
    long long dist;
    int node;
} HeapNode;

static void swap(HeapNode *a, HeapNode *b) {
    HeapNode t = *a;
    *a = *b;
    *b = t;
}

static void push(HeapNode *heap, int *size, long long d, int u) {
    int i = (*size)++;
    heap[i].dist = d;
    heap[i].node = u;

    while (i > 0) {
        int p = (i - 1) / 2;
        if (heap[p].dist <= heap[i].dist) break;
        swap(&heap[p], &heap[i]);
        i = p;
    }
}

static HeapNode pop(HeapNode *heap, int *size) {
    HeapNode res = heap[0];
    heap[0] = heap[--(*size)];

    int i = 0;
    while (1) {
        int l = i * 2 + 1;
        int r = i * 2 + 2;
        int s = i;

        if (l < *size && heap[l].dist < heap[s].dist) s = l;
        if (r < *size && heap[r].dist < heap[s].dist) s = r;

        if (s == i) break;

        swap(&heap[s], &heap[i]);
        i = s;
    }
    return res;
}

int head[100005];
Edge edgesList[200005];
int idx;

void addEdge(int u, int v, int w) {
    edgesList[idx].to = v;
    edgesList[idx].w = w;
    edgesList[idx].next = head[u];
    head[u] = idx++;
}

bool check(int mid, int n, long long k) {
    long long *dist = malloc(sizeof(long long) * n);

    for (int i = 0; i < n; i++)
        dist[i] = LLONG_MAX / 4;

    HeapNode *heap = malloc(sizeof(HeapNode) * 200005);
    int sz = 0;

    dist[0] = 0;
    push(heap, &sz, 0, 0);

    while (sz) {
        HeapNode cur = pop(heap, &sz);

        if (cur.dist > k) {
            free(dist);
            free(heap);
            return false;
        }

        if (cur.node == n - 1) {
            free(dist);
            free(heap);
            return true;
        }

        if (cur.dist != dist[cur.node])
            continue;

        for (int e = head[cur.node]; e != -1; e = edgesList[e].next) {
            if (edgesList[e].w < mid)
                continue;

            int v = edgesList[e].to;
            long long nd = cur.dist + edgesList[e].w;

            if (nd < dist[v]) {
                dist[v] = nd;
                push(heap, &sz, nd, v);
            }
        }
    }

    free(dist);
    free(heap);
    return false;
}

int findMaxPathScore(int** edges, int edgesSize, int* edgesColSize,
                     bool* online, int onlineSize, long long k) {

    memset(head, -1, sizeof(head));
    idx = 0;

    int lo = INT_MAX;
    int hi = 0;

    for (int i = 0; i < edgesSize; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];

        if (!online[u] || !online[v])
            continue;

        addEdge(u, v, w);

        if (w < lo) lo = w;
        if (w > hi) hi = w;
    }

    while (lo < hi) {
        int mid = (lo + hi + 1) / 2;

        if (check(mid, onlineSize, k))
            lo = mid;
        else
            hi = mid - 1;
    }

    return check(lo, onlineSize, k) ? lo : -1;
}
