
class Solution {
    public long minSumSquareDiff(int[] nums1, int[] nums2, int k1, int k2) {
        int n = nums1.length;
        long k = (long) k1 + k2;
        int[] diff = new int[n];

        long total = 0;
        int max = 0;

        for (int i = 0; i < n; i++) {
            diff[i] = Math.abs(nums1[i] - nums2[i]);
            total += diff[i];
            max = Math.max(max, diff[i]);
        }

        if (total <= k) return 0;

        int left = 0, right = max;

        while (left < right) {
            int mid = left + (right - left) / 2;
            long ops = 0;

            for (int d : diff) {
                ops += Math.max(0, d - mid);
            }

            if (ops <= k) {
                right = mid;
            } else {
                left = mid + 1;
            }
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

        long ans = 0;

        for (int d : diff) {
            ans += (long) d * d;
        }

        return ans;
    }
}
