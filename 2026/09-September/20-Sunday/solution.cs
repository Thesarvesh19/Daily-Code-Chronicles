public class Solution
{
    public int ReverseDegree(string s)
    {
        int ans = 0;

        for (int i = 0; i < s.Length; i++)
        {
            int position = i + 1;
            int reverseValue = 26 - (s[i] - 'a');

            ans += position * reverseValue;
        }

        return ans;
    }
}
