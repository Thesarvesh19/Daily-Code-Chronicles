#include <stdio.h>
#include <stdlib.h>
 
#define MAXN 101

int minimumDistance(int* nums, int numsSize) {
    int* pos[MAXN];
    int count[MAXN] = {0};

    // allocate memory
    for (int i = 0; i < MAXN; i++) {
        pos[i] = (int*)malloc(sizeof(int) * numsSize);
    }

    // store indices
    for (int i = 0; i < numsSize; i++) {
        int val = nums[i];
        pos[val][count[val]++] = i;
    }

    int ans = 1e9;

    for (int v = 0; v < MAXN; v++) {
        if (count[v] >= 3) {
            for (int i = 0; i + 2 < count[v]; i++) {
                int dist = 2 * (pos[v][i+2] - pos[v][i]);
                if (dist < ans) ans = dist;
            }
        }
    }

    // free memory
    for (int i = 0; i < MAXN; i++) {
        free(pos[i]);
    }

    return (ans == 1e9) ? -1 : ans;
}
