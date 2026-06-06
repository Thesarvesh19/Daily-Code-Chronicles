class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int total = 0;

        for (int x : nums)
            total += x;

        int leftSum = 0;
        vector<int> ans(nums.size());

        for (int i = 0; i < nums.size(); i++) {
            total -= nums[i];

            ans[i] = abs(leftSum - total);

            leftSum += nums[i];
        }

        return ans;
    }
};
