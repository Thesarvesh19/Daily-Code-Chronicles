#include <stdlib.h>
#include <stdbool.h>

int largestInteger(int* nums, int numsSize, int k) {
    int *freq = (int*)calloc(100001, sizeof(int));
    int ans = -1;

    for (int i = 0; i <= numsSize - k; i++) {
        bool *seen = (bool*)calloc(100001, sizeof(bool));

        for (int j = i; j < i + k; j++) {
            seen[nums[j]] = true;
        }

        for (int j = 0; j <= 100000; j++) {
            if (seen[j]) {
                freq[j]++;
            }
        }

        free(seen);
    }

    for (int i = 0; i <= 100000; i++) {
        if (freq[i] == 1) {
            ans = i;
        }
    }

    free(freq);
    return ans;
}
