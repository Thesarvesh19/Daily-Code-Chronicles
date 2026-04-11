#include <stdio.h>
#include <stdlib.h>

#define MAXN 100001

typedef struct {
    int *arr;
    int size;
    int capacity;
} List;

int minimumDistance(int* nums, int n) {
    int count[MAXN] = {0};
    
    // 1st pass: count frequency
    for (int i = 0; i < n; i++) {
        count[nums[i]]++;
    }
    
    // create lists with exact size
    List pos[MAXN];
    for (int i = 0; i < MAXN; i++) {
        if (count[i] > 0) {
            pos[i].arr = (int*)malloc(count[i] * sizeof(int));
            pos[i].size = 0;
            pos[i].capacity = count[i];
        }
    }
    
    // 2nd pass: fill indices
    for (int i = 0; i < n; i++) {
        int v = nums[i];
        pos[v].arr[pos[v].size++] = i;
    }
    
    int ans = 1e9;
    
    // process each value
    for (int v = 1; v < MAXN; v++) {
        if (count[v] >= 3) {
            for (int i = 0; i <= count[v] - 3; i++) {
                int dist = 2 * (pos[v].arr[i + 2] - pos[v].arr[i]);
                if (dist < ans) ans = dist;
            }
        }
    }
    
    return ans == 1e9 ? -1 : ans;
}
