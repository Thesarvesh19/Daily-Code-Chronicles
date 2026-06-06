class Solution {
    public int[] leftRightDifference(int[] nums) {
        int total = 0;

        for (int x : nums)
            total += x;

        int leftSum = 0;
        int[] ans = new int[nums.length];

        for (int i = 0; i < nums.length; i++) {
            total -= nums[i];

            ans[i] = Math.abs(leftSum - total);

            leftSum += nums[i];
        }

        return ans;
    }
}
