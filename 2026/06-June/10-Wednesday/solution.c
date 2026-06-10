long long maximumSubarrayValue(int* nums, int numsSize, int k) {
    int total = numsSize * (numsSize + 1) / 2;

    long long* vals = (long long*)malloc(sizeof(long long) * total);
    int idx = 0;

    for (int i = 0; i < numsSize; i++) {
        int mn = nums[i];
        int mx = nums[i];

        for (int j = i; j < numsSize; j++) {
            if (nums[j] < mn) mn = nums[j];
            if (nums[j] > mx) mx = nums[j];

            vals[idx++] = (long long)mx - mn;
        }
    }

    int cmp(const void* a, const void* b) {
        long long x = *(long long*)a;
        long long y = *(long long*)b;
        return (x < y) - (x > y);
    }

    qsort(vals, total, sizeof(long long), cmp);

    long long ans = 0;
    for (int i = 0; i < k; i++) {
        ans += vals[i];
    }

    free(vals);
    return ans;
}
