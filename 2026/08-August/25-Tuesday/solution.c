#include <stdlib.h>

int missingMultiple(int* nums, int numsSize, int k) {
    int maxVal = numsSize * k + k;
    int* present = (int*)calloc(maxVal + 1, sizeof(int));

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] <= maxVal)
            present[nums[i]] = 1;
    }

    for (int x = k; x <= maxVal; x += k) {
        if (!present[x]) {
            free(present);
            return x;
        }
    }

    free(present);
    return -1;
}
