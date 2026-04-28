#include <stdlib.h>

int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int minOperations(int** grid, int gridSize, int* gridColSize, int x) {
    int n = gridSize * gridColSize[0];
    int* nums = (int*)malloc(n * sizeof(int));

    int idx = 0;
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridColSize[i]; j++) {
            nums[idx++] = grid[i][j];
        }
    }

    qsort(nums, n, sizeof(int), cmp);

    int base = nums[0] % x;
    for (int i = 0; i < n; i++) {
        if (nums[i] % x != base) {
            free(nums);
            return -1;
        }
    }

    int median = nums[n / 2];
    int ops = 0;

    for (int i = 0; i < n; i++) {
        ops += abs(nums[i] - median) / x;
    }

    free(nums);
    return ops;
}
