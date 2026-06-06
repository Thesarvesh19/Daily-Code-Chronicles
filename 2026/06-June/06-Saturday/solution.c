#include <stdlib.h>

int* leftRightDifference(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;

    int* ans = (int*)malloc(numsSize * sizeof(int));

    int total = 0;

    for (int i = 0; i < numsSize; i++)
        total += nums[i];

    int leftSum = 0;

    for (int i = 0; i < numsSize; i++) {
        total -= nums[i];

        int diff = leftSum - total;
        if (diff < 0)
            diff = -diff;

        ans[i] = diff;

        leftSum += nums[i];
    }

    return ans;
}
