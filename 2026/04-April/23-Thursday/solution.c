// 2615. Sum of Distances

#include <stdio.h>
#include <stdlib.h>

typedef long long ll;

typedef struct {
    int *data;
    int size;
    int capacity;
} Vector;

void push_back(Vector *v, int val) {
    if (v->size == v->capacity) {
        v->capacity = v->capacity == 0 ? 2 : v->capacity * 2;
        v->data = (int *)realloc(v->data, v->capacity * sizeof(int));
    }
    v->data[v->size++] = val;
}

// Hash map using sorting trick (since nums[i] ≤ 1e9)
typedef struct {
    int val;
    int idx;
} Pair;

int cmp(const void *a, const void *b) {
    Pair *p1 = (Pair *)a;
    Pair *p2 = (Pair *)b;
    if (p1->val != p2->val)
        return p1->val - p2->val;
    return p1->idx - p2->idx;
}

long long* distance(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    
    ll *res = (ll *)calloc(numsSize, sizeof(ll));
    
    // Step 1: create value-index pairs
    Pair *arr = (Pair *)malloc(numsSize * sizeof(Pair));
    for (int i = 0; i < numsSize; i++) {
        arr[i].val = nums[i];
        arr[i].idx = i;
    }
    
    // Step 2: sort by value
    qsort(arr, numsSize, sizeof(Pair), cmp);
    
    // Step 3: process groups
    int i = 0;
    while (i < numsSize) {
        int j = i;
        
        // find same value group
        while (j < numsSize && arr[j].val == arr[i].val)
            j++;
        
        int n = j - i;
        
        // collect indices
        int *indices = (int *)malloc(n * sizeof(int));
        for (int k = 0; k < n; k++) {
            indices[k] = arr[i + k].idx;
        }
        
        // sort indices (important)
        qsort(indices, n, sizeof(int), cmp);
        
        // prefix sum
        ll *prefix = (ll *)malloc((n + 1) * sizeof(ll));
        prefix[0] = 0;
        for (int k = 0; k < n; k++) {
            prefix[k + 1] = prefix[k] + indices[k];
        }
        
        // compute distances
        for (int k = 0; k < n; k++) {
            int idx = indices[k];
            
            ll left = (ll)idx * k - prefix[k];
            ll right = (prefix[n] - prefix[k + 1]) - (ll)idx * (n - k - 1);
            
            res[idx] = left + right;
        }
        
        free(indices);
        free(prefix);
        
        i = j;
    }
    
    free(arr);
    return res;
}
