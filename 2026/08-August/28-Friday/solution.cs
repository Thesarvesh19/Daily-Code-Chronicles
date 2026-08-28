using System;

public class Solution
{
    public string LexPalindromicPermutation(string s, string target)
    {
        int n = s.Length;
        int[] count = new int[26];

        foreach (char ch in s)
            count[ch - 'a']++;

        // A palindrome can have at most one odd-frequency character.
        int odd = 0;
        char middle = '\0';

        for (int i = 0; i < 26; i++)
        {
            if (count[i] % 2 == 1)
            {
                odd++;
                middle = (char)('a' + i);
            }
        }

        if (odd > 1)
            return "";

        // Characters available for the left half.
        int[] half = new int[26];

        for (int i = 0; i < 26; i++)
            half[i] = count[i] / 2;

        string left = "";

        string BuildPalindrome(string l)
        {
            string result = l;

            if (middle != '\0')
                result += middle;

            for (int i = l.Length - 1; i >= 0; i--)
                result += l[i];

            return result;
        }

        for (int pos = 0; pos < n / 2; pos++)
        {
            bool found = false;

            // Try the smallest possible character.
            for (int c = 0; c < 26; c++)
            {
                if (half[c] == 0)
                    continue;

                half[c]--;
                left += (char)('a' + c);

                // Fill the remaining positions with
                // the largest possible characters.
                string remaining = "";

                for (int x = 25; x >= 0; x--)
                {
                    if (half[x] > 0)
                        remaining += new string((char)('a' + x), half[x]);
                }

                string candidateLeft = left + remaining;
                string candidate = BuildPalindrome(candidateLeft);

                if (string.Compare(candidate, target, StringComparison.Ordinal) > 0)
                {
                    found = true;
                    break;
                }

                // Undo the choice.
                left = left.Substring(0, left.Length - 1);
                half[c]++;
            }

            if (!found)
                return "";
        }

        string answer = BuildPalindrome(left);

        return string.Compare(answer, target, StringComparison.Ordinal) > 0
            ? answer
            : "";
    }
}
