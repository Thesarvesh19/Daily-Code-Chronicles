public class Solution
{
    public string MapWordWeights(string[] words, int[] weights)
    {
        StringBuilder ans = new StringBuilder();

        foreach (string word in words)
        {
            int sum = 0;

            foreach (char c in word)
            {
                sum += weights[c - 'a'];
            }

            sum %= 26;
            ans.Append((char)('a' + (25 - sum)));
        }

        return ans.ToString();
    }
}
