
class Solution {
    public int minMoves(int[] nums) {
        int minVal = Integer.MAX_VALUE;
        int sum = 0;

        for (int num : nums) { 
            minVal = Math.min(minVal, num);
            sum += num;
        }

        return sum - (nums.length * minVal);
    }
}
