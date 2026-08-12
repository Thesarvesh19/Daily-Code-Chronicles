public class Solution {
    public int MissingInteger(int[] nums) {
        int sum = nums[0];

        // Sum of the longest sequential prefix
        for (int i = 1; i < nums.Length; i++) {
            if (nums[i] == nums[i - 1] + 1) {
                sum += nums[i];
            } else {
                break;
            }
        }

        // Store all elements
        HashSet<int> set = new HashSet<int>(nums);

        // Find smallest missing integer >= sum
        while (set.Contains(sum)) {
            sum++;
        }

        return sum;
    }
}
