#define MOD 1000000007LL

typedef struct Node {
    int val;
    struct Node* next;
} Node;
 
long long modPow(long long a, long long b) {
    long long res = 1;

    while (b > 0) {
        if (b & 1)
            res = (res * a) % MOD;

        a = (a * a) % MOD;
        b >>= 1;
    }

    return res;
}

int assignEdgeWeights(int** edges, int edgesSize, int* edgesColSize) {
    int n = edgesSize + 1;

    Node** graph = (Node**)calloc(n + 1, sizeof(Node*));

    for (int i = 0; i < edgesSize; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        Node* a = (Node*)malloc(sizeof(Node));
        a->val = v;
        a->next = graph[u];
        graph[u] = a;

        Node* b = (Node*)malloc(sizeof(Node));
        b->val = u;
        b->next = graph[v];
        graph[v] = b;
    }

    int* queue = (int*)malloc((n + 5) * sizeof(int));
    int front = 0, rear = 0;

    int* vis = (int*)calloc(n + 1, sizeof(int));

    queue[rear++] = 1;
    vis[1] = 1;

    int depth = -1;

    while (front < rear) {
        int sz = rear - front;
        depth++;

        while (sz--) {
            int u = queue[front++];

            for (Node* cur = graph[u]; cur; cur = cur->next) {
                int v = cur->val;

                if (!vis[v]) {
                    vis[v] = 1;
                    queue[rear++] = v;
                }
            }
        }
    }

    free(queue);
    free(vis);

    return (int)modPow(2, depth - 1);
}
