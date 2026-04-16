#include <stdlib.h>
#include <math.h>

typedef struct {
    int val;
    int idx;
} Pair;

int cmp(const void *a, const void *b) {
    Pair *p1 = (Pair *)a;
    Pair *p2 = (Pair *)b;
    if (p1->val != p2->val) return p1->val - p2->val;
    return p1->idx - p2->idx;
}

int* solveQueries(int* nums, int n, int* queries, int qSize, int* returnSize) {
    Pair *arr = malloc(n * sizeof(Pair));
    for (int i = 0; i < n; i++) {
        arr[i].val = nums[i];
        arr[i].idx = i;
    }

    qsort(arr, n, sizeof(Pair), cmp);

    int *left = malloc(n * sizeof(int));
    int *right = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        left[i] = right[i] = -1;
    }

    int i = 0;
    while (i < n) {
        int j = i;
        while (j < n && arr[j].val == arr[i].val) j++;

        if (j - i > 1) {
            for (int k = i; k < j; k++) {
                int prev = arr[(k - 1 >= i) ? k - 1 : j - 1].idx;
                int next = arr[(k + 1 < j) ? k + 1 : i].idx;

                left[arr[k].idx] = prev;
                right[arr[k].idx] = next;
            }
        }

        i = j;
    }

    int *res = malloc(qSize * sizeof(int));

    for (int i = 0; i < qSize; i++) {
        int q = queries[i];

        if (left[q] == -1) {
            res[i] = -1;
            continue;
        }

        int d1 = abs(q - left[q]);
        int d2 = abs(q - right[q]);

        d1 = (d1 < n - d1) ? d1 : n - d1;
        d2 = (d2 < n - d2) ? d2 : n - d2;

        res[i] = (d1 < d2) ? d1 : d2;
    }

    free(arr);
    free(left);
    free(right);

    *returnSize = qSize;
    return res;
}
