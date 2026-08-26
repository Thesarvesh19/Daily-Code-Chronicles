public class Solution
{
    public string ShortestBeautifulSubstring(string s, int k)
    {
        int left = 0;
        int ones = 0;
        string ans = "";

        for (int right = 0; right < s.Length; right++)
        {
            if (s[right] == '1')
                ones++;

            while (ones > k)
            {
                if (s[left] == '1')
                    ones--;
                left++;
            }

            while (ones == k && s[left] == '0')
                left++;

            if (ones == k)
            {
                string curr = s.Substring(left, right - left + 1);

                if (ans == "" ||
                    curr.Length < ans.Length ||
                    (curr.Length == ans.Length && string.Compare(curr, ans, StringComparison.Ordinal) < 0))
                {
                    ans = curr;
                }
            }
        }

        return ans;
    }
}
