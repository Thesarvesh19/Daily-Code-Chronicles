
class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        long long k = (long long)k1 + k2;
        vector<int> diff(n);

        long long total = 0;
        int mx = 0;

        for (int i = 0; i < n; i++) {
            diff[i] = abs(nums1[i] - nums2[i]);
            total += diff[i];
            mx = max(mx, diff[i]);
        }

        if (total <= k) return 0;

        int left = 0, right = mx;

        while (left < right) {
            int mid = left + (right - left) / 2;
            long long ops = 0;

            for (int d : diff) {
                ops += max(0, d - mid);
            }

            if (ops <= k)
                right = mid;
            else
                left = mid + 1;
        }

        long long ans = 0;

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

        for (int d : diff) {
            ans += 1LL * d * d;
        }

        return ans;
    }
};
