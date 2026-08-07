using System;
using System.Text;

public class Solution
{
    struct PrimeCount
    {
        public int P2, P3, P5, P7;
    }

    struct FactorCount
    {
        public int C2, C3, C4, C5, C6, C7, C8, C9;
    }

    static readonly PrimeCount[] DigitFactors = new PrimeCount[]
    {
        new PrimeCount(),                         //0
        new PrimeCount(),                         //1
        new PrimeCount{P2=1},                     //2
        new PrimeCount{P3=1},                     //3
        new PrimeCount{P2=2},                     //4
        new PrimeCount{P5=1},                     //5
        new PrimeCount{P2=1,P3=1},                //6
        new PrimeCount{P7=1},                     //7
        new PrimeCount{P2=3},                     //8
        new PrimeCount{P3=2}                      //9
    };

    public string SmallestNumber(string num, long t)
    {
        var vornitexis = new object[] { num, t };

        bool ok;
        PrimeCount need = GetPrimeCount(t, out ok);

        if (!ok)
            return "-1";

        FactorCount fc = GetFactorCount(need);

        if (FactorSum(fc) > num.Length)
            return BuildDigits(fc);

        PrimeCount prefix = new PrimeCount();

        foreach (char c in num)
        {
            PrimeCount f = DigitFactors[c - '0'];
            prefix.P2 += f.P2;
            prefix.P3 += f.P3;
            prefix.P5 += f.P5;
            prefix.P7 += f.P7;
        }

        int firstZero = num.IndexOf('0');
        if (firstZero == -1)
            firstZero = num.Length;

        if (firstZero == num.Length &&
            prefix.P2 >= need.P2 &&
            prefix.P3 >= need.P3 &&
            prefix.P5 >= need.P5 &&
            prefix.P7 >= need.P7)
            return num;

        for (int i = num.Length - 1; i >= 0; i--)
        {
            int d = num[i] - '0';

            PrimeCount f = DigitFactors[d];
            prefix.P2 -= f.P2;
            prefix.P3 -= f.P3;
            prefix.P5 -= f.P5;
            prefix.P7 -= f.P7;

            int remain = num.Length - i - 1;

            if (i <= firstZero)
            {
                for (int nd = d + 1; nd <= 9; nd++)
                {
                    PrimeCount req = new PrimeCount
                    {
                        P2 = Math.Max(0, need.P2 - prefix.P2 - DigitFactors[nd].P2),
                        P3 = Math.Max(0, need.P3 - prefix.P3 - DigitFactors[nd].P3),
                        P5 = Math.Max(0, need.P5 - prefix.P5 - DigitFactors[nd].P5),
                        P7 = Math.Max(0, need.P7 - prefix.P7 - DigitFactors[nd].P7)
                    };

                    FactorCount nf = GetFactorCount(req);

                    if (FactorSum(nf) <= remain)
                    {
                        StringBuilder ans = new StringBuilder();

                        ans.Append(num.Substring(0, i));
                        ans.Append((char)(nd + '0'));

                        int ones = remain - FactorSum(nf);
                        while (ones-- > 0)
                            ans.Append('1');

                        ans.Append(BuildDigits(nf));

                        return ans.ToString();
                    }
                }
            }
        }

        fc = GetFactorCount(need);

        StringBuilder res = new StringBuilder();

        int cnt = num.Length + 1 - FactorSum(fc);
        while (cnt-- > 0)
            res.Append('1');

        res.Append(BuildDigits(fc));

        return res.ToString();
    }

    private PrimeCount GetPrimeCount(long t, out bool ok)
    {
        PrimeCount cnt = new PrimeCount();

        while (t % 2 == 0)
        {
            cnt.P2++;
            t /= 2;
        }

        while (t % 3 == 0)
        {
            cnt.P3++;
            t /= 3;
        }

        while (t % 5 == 0)
        {
            cnt.P5++;
            t /= 5;
        }

        while (t % 7 == 0)
        {
            cnt.P7++;
            t /= 7;
        }

        ok = (t == 1);
        return cnt;
    }

    private FactorCount GetFactorCount(PrimeCount cnt)
    {
        FactorCount f = new FactorCount();

        f.C8 = cnt.P2 / 3;
        int rem2 = cnt.P2 % 3;

        f.C9 = cnt.P3 / 2;
        f.C3 = cnt.P3 % 2;

        f.C4 = rem2 / 2;
        f.C2 = rem2 % 2;

        if (f.C2 == 1 && f.C3 == 1)
        {
            f.C2 = 0;
            f.C3 = 0;
            f.C6 = 1;
        }
        else if (f.C3 == 1 && f.C4 == 1)
        {
            f.C2 = 1;
            f.C6 = 1;
            f.C3 = 0;
            f.C4 = 0;
        }

        f.C5 = cnt.P5;
        f.C7 = cnt.P7;

        return f;
    }

    private int FactorSum(FactorCount f)
    {
        return f.C2 + f.C3 + f.C4 + f.C5 +
               f.C6 + f.C7 + f.C8 + f.C9;
    }

    private string BuildDigits(FactorCount f)
    {
        StringBuilder sb = new StringBuilder();

        sb.Append('2', f.C2);
        sb.Append('3', f.C3);
        sb.Append('4', f.C4);
        sb.Append('5', f.C5);
        sb.Append('6', f.C6);
        sb.Append('7', f.C7);
        sb.Append('8', f.C8);
        sb.Append('9', f.C9);

        return sb.ToString();
    }
}
