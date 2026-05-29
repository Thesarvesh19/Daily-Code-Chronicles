public class Solution {
    public int MinElement(int[] nums) {
        int min = int.MaxValue;

        foreach (int num in nums) {
            int n = num, sum = 0;
            while (n > 0) {
                sum += n % 10;
                n /= 10;
            }
            min = Math.Min(min, sum);
        }

        return min;
    }
}
