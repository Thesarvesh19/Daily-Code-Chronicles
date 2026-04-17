// Minimum Absolute Distance Between Mirror Pairs

#include <stdio.h>
#include <stdlib.h>

#define MAX 200001

int reverse(int x) {
    int rev = 0;
    while (x > 0) {
        rev = rev * 10 + x % 10;
        x /= 10;
    }
    return rev;
}

int minMirrorPairDistance(int* nums, int numsSize) {
    int* last_seen = (int*)malloc(sizeof(int) * MAX);
    for (int i = 0; i < MAX; i++) last_seen[i] = -1;

    int ans = 1e9;

    for (int j = 0; j < numsSize; j++) {
        if (nums[j] < MAX && last_seen[nums[j]] != -1) {
            int dist = j - last_seen[nums[j]];
            if (dist < ans) ans = dist;
        }

        int rev = reverse(nums[j]);
        if (rev < MAX)
            last_seen[rev] = j;
    }

    free(last_seen);
    return ans == 1e9 ? -1 : ans;
}
