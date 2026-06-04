public class Solution
{
    private int Waviness(int num)
    {
        string s = num.ToString();

        if (s.Length < 3)
            return 0;

        int count = 0;

        for (int i = 1; i < s.Length - 1; i++)
        {
            if ((s[i] > s[i - 1] && s[i] > s[i + 1]) ||
                (s[i] < s[i - 1] && s[i] < s[i + 1]))
            {
                count++;
            }
        }

        return count;
    }

    public int TotalWaviness(int num1, int num2)
    {
        int ans = 0;

        for (int num = num1; num <= num2; num++)
        {
            ans += Waviness(num);
        }

        return ans;
    }
}
