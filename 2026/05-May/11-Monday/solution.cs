public class Solution {
    public int[] SeparateDigits(int[] nums) {
        List<int> result = new List<int>();

        foreach (int num in nums) {
            string s = num.ToString();

            foreach (char c in s) {
                result.Add(c - '0');
            }
        }

        return result.ToArray();
    }
}
