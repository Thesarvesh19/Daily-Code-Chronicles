import java.util.Arrays;

class Solution {
    public boolean isGood(int[] nums) {
        Arrays.sort(nums);

        int n = nums.length;
 
        // Last two elements should be n-1
        if (nums[n - 1] != n - 1 || nums[n - 2] != n - 1)
            return false;

        // First n-2 elements should be 1 to n-2
        for (int i = 0; i < n - 2; i++) {
            if (nums[i] != i + 1)
                return false;
        }

        return true;
    }
}
