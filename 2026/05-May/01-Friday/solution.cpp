class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        long sum = 0, f = 0;

        for (int i = 0; i < n; i++) {
            sum += nums[i];
            f += (long)i * nums[i];
        }

        long res = f; 

        for (int k = 1; k < n; k++) {
            f = f + sum - (long)n * nums[n - k];
            res = max(res, f);
        }

        return res;
    }
};
