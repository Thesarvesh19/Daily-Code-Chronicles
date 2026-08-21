using System;

public class Solution
{
    public long FindKthSmallest(int[] coins, int k)
    {
        int n = coins.Length;

        long Gcd(long a, long b)
        {
            while (b != 0)
            {
                long temp = a % b;
                a = b;
                b = temp;
            }
            return a;
        }

        long Lcm(long a, long b)
        {
            return a / Gcd(a, b) * b;
        }

        long Count(long x)
        {
            long total = 0;

            for (int mask = 1; mask < (1 << n); mask++)
            {
                long multiple = 1;
                int bits = 0;
                bool valid = true;

                for (int i = 0; i < n; i++)
                {
                    if ((mask & (1 << i)) != 0)
                    {
                        bits++;
                        multiple = Lcm(multiple, coins[i]);

                        if (multiple > x)
                        {
                            valid = false;
                            break;
                        }
                    }
                }

                if (!valid)
                    continue;

                long cnt = x / multiple;

                if (bits % 2 == 1)
                    total += cnt;
                else
                    total -= cnt;
            }

            return total;
        }

        long minCoin = coins[0];

        foreach (int coin in coins)
            minCoin = Math.Min(minCoin, coin);

        long left = 1;
        long right = minCoin * k;

        while (left < right)
        {
            long mid = left + (right - left) / 2;

            if (Count(mid) >= k)
                right = mid;
            else
                left = mid + 1;
        }

        return left;
    }
}
