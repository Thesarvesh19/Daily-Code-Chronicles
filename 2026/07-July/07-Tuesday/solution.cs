public class Solution
{
    public long SumAndMultiply(int n)
    {
        List<int> digits = new List<int>();

        while (n > 0)
        {
            int d = n % 10;
            if (d != 0)
                digits.Add(d);
            n /= 10;
        }

        digits.Reverse();

        long value = 0;
        int sum = 0;

        foreach (int d in digits)
        {
            value = value * 10 + d;
            sum += d;
        }

        return value * sum;
    }
}
