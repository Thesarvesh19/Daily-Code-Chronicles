/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdlib.h>
#include <stdbool.h>

int* findMissingElements(int* nums, int numsSize, int* returnSize) {
    int lo = 101, hi = 0;
    bool seen[101] = {false};

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] < lo) lo = nums[i];
        if (nums[i] > hi) hi = nums[i];
        seen[nums[i]] = true;
    }

    int* ans = (int*)malloc(sizeof(int) * 100);
    *returnSize = 0;

    for (int x = lo + 1; x < hi; x++) {
        if (!seen[x]) {
            ans[(*returnSize)++] = x;
        }
    }

    return ans;
}
