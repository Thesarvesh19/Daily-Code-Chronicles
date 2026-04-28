import java.util.*;

class Solution {
    public int minOperations(int[][] grid, int x) {
        List<Integer> nums = new ArrayList<>();

        for (int[] row : grid) {
            for (int num : row) {
                nums.add(num);
            }
        }

        Collections.sort(nums);

        int base = nums.get(0) % x;
        for (int num : nums) {
            if (num % x != base) return -1;
        }

        int median = nums.get(nums.size() / 2);
        int ops = 0;

        for (int num : nums) {
            ops += Math.abs(num - median) / x;
        }

        return ops;
    }
}
