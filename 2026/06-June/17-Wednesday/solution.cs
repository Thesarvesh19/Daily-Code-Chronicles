public class Solution
{
    public char ProcessStr(string s, long k)
    {
        long len = 0;

        foreach (char c in s)
        {
            if (c == '*')
            {
                len = Math.Max(0, len - 1);
            }
            else if (c == '#')
            {
                len <<= 1;
            }
            else if (c != '%')
            {
                len++;
            }
        }

        if (k >= len)
        {
            return '.';
        }

        for (int i = s.Length - 1; i >= 0; --i)
        {
            char c = s[i];

            if (c == '*')
            {
                len++;
            }
            else if (c == '#')
            {
                len /= 2;
                if (k >= len)
                {
                    k -= len;
                }
            }
            else if (c == '%')
            {
                k = len - 1 - k;
            }
            else
            {
                len--;
                if (k == len)
                {
                    return c;
                }
            }
        }

        return '.';
    }
}
