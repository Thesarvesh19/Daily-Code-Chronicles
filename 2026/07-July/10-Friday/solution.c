#include <stdlib.h>
#include <string.h>
#include <limits.h>

typedef struct {
    int value;
    int index;
} Pair;

static int compare(const void *a, const void *b) {
    Pair *x = (Pair *)a;
    Pair *y = (Pair *)b;

    if (x->value != y->value)
        return x->value - y->value;
    return x->index - y->index;
}

static int **jump;
static int maxLevel;

static int minJumps(int start, int end, int level) {
    if (start == end)
        return 0;

    if (jump[start][0] >= end)
        return 1;

    if (jump[start][level] < end)
        return INT_MAX;

    int j;
    for (j = level; j >= 0; --j) {
        if (jump[start][j] < end)
            break;
    }

    int next = minJumps(jump[start][j], end, j);

    if (next == INT_MAX)
        return INT_MAX;

    return (1 << j) + next;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* pathExistenceQueries(
    int n,
    int* nums,
    int maxDiff,
    int** queries,
    int queriesSize,
    int* queriesColSize,
    int* returnSize
) {
    Pair *arr = (Pair *)malloc(sizeof(Pair) * n);

    for (int i = 0; i < n; i++) {
        arr[i].value = nums[i];
        arr[i].index = i;
    }

    qsort(arr, n, sizeof(Pair), compare);

    int *sortedNums = (int *)malloc(sizeof(int) * n);
    int *indexMap = (int *)malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++) {
        sortedNums[i] = arr[i].value;
        indexMap[arr[i].index] = i;
    }

    maxLevel = 0;
    while ((1 << maxLevel) <= n)
        maxLevel++;
    maxLevel++;

    jump = (int **)malloc(sizeof(int *) * n);
    for (int i = 0; i < n; i++) {
        jump[i] = (int *)calloc(maxLevel, sizeof(int));
    }

    int right = 0;
    for (int i = 0; i < n; i++) {
        while (right + 1 < n &&
               sortedNums[right + 1] - sortedNums[i] <= maxDiff)
            right++;

        jump[i][0] = right;
    }

    for (int level = 1; level < maxLevel; level++) {
        for (int i = 0; i < n; i++) {
            int prev = jump[i][level - 1];
            jump[i][level] = jump[prev][level - 1];
        }
    }

    int *answer = (int *)malloc(sizeof(int) * queriesSize);

    for (int i = 0; i < queriesSize; i++) {
        int u = queries[i][0];
        int v = queries[i][1];

        int left = indexMap[u];
        int rightPos = indexMap[v];

        if (left > rightPos) {
            int temp = left;
            left = rightPos;
            rightPos = temp;
        }

        int res = minJumps(left, rightPos, maxLevel - 1);

        if (res == INT_MAX)
            answer[i] = -1;
        else
            answer[i] = res;
    }

    for (int i = 0; i < n; i++)
        free(jump[i]);

    free(jump);
    free(arr);
    free(sortedNums);
    free(indexMap);

    *returnSize = queriesSize;
    return answer;
}
