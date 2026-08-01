#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>

int **memo;

int dfs(int* nums, int l, int r) {
    if (l == r)
        return nums[l];

    if (memo[l][r] != INT_MIN)
        return memo[l][r];

    int left = nums[l] - dfs(nums, l + 1, r);
    int right = nums[r] - dfs(nums, l, r - 1);

    memo[l][r] = left > right ? left : right;
    return memo[l][r];
}

bool predictTheWinner(int* nums, int numsSize) {

    memo = (int**)malloc(numsSize * sizeof(int*));

    for (int i = 0; i < numsSize; i++) {
        memo[i] = (int*)malloc(numsSize * sizeof(int));
        for (int j = 0; j < numsSize; j++)
            memo[i][j] = INT_MIN;
    }

    bool ans = dfs(nums, 0, numsSize - 1) >= 0;

    for (int i = 0; i < numsSize; i++)
        free(memo[i]);
    free(memo);

    return ans;
}
