
#include <stdlib.h>

long long minSumSquareDiff(int* nums1, int nums1Size,
                           int* nums2, int nums2Size,
                           int k1, int k2) {
    int n = nums1Size;
    long long k = (long long)k1 + k2;
    int* diff = (int*)malloc(n * sizeof(int));

    long long total = 0;
    int maxDiff = 0;

    for (int i = 0; i < n; i++) {
        diff[i] = abs(nums1[i] - nums2[i]);
        total += diff[i];
        if (diff[i] > maxDiff)
            maxDiff = diff[i];
    }

    if (total <= k) {
        free(diff);
        return 0;
    }

    int left = 0, right = maxDiff;

    while (left < right) {
        int mid = left + (right - left) / 2;
        long long ops = 0;

        for (int i = 0; i < n; i++) {
            if (diff[i] > mid)
                ops += diff[i] - mid;
        }

        if (ops <= k)
            right = mid;
        else
            left = mid + 1;
    }

    for (int i = 0; i < n; i++) {
        if (diff[i] > left) {
            k -= diff[i] - left;
            diff[i] = left;
        }
    }

    for (int i = 0; i < n && k > 0; i++) {
        if (diff[i] == left && left > 0) {
            diff[i]--;
            k--;
        }
    }

    long long ans = 0;

    for (int i = 0; i < n; i++) {
        ans += (long long)diff[i] * diff[i];
    }

    free(diff);
    return ans;
}
