
public class Solution {
    public int MinMoves(int[] nums) { 
        int minVal = int.MaxValue;
        int sum = 0;

        foreach (int num in nums) {
            minVal = Math.Min(minVal, num);
            sum += num;
        }

        return sum - (nums.Length * minVal);
    }
}
