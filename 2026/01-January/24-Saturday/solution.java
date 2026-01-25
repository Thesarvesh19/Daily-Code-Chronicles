import java.util.Arrays;

class Solution {
    public int minPairSum(int[] nums) {
        // Step 1: Sort the array
        Arrays.sort(nums);

        int maxSum = 0;
        int left = 0;
        int right = nums.length - 1;

        // Step 2: Pair smallest with largest
        while (left < right) {
            int pairSum = nums[left] + nums[right];
            maxSum = Math.max(maxSum, pairSum);
            left++;
            right--;
        }

        return maxSum;
    }
}
