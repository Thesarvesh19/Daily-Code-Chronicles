public class Solution
{
    public string SmallestSubsequence(string s)
    {
        int[] last = new int[26];

        for (int i = 0; i < s.Length; i++)
            last[s[i] - 'a'] = i;

        bool[] used = new bool[26];
        var stack = new List<char>();

        for (int i = 0; i < s.Length; i++)
        {
            char ch = s[i];

            if (used[ch - 'a'])
                continue;

            while (stack.Count > 0 &&
                   stack[^1] > ch &&
                   last[stack[^1] - 'a'] > i)
            {
                used[stack[^1] - 'a'] = false;
                stack.RemoveAt(stack.Count - 1);
            }

            stack.Add(ch);
            used[ch - 'a'] = true;
        }

        return new string(stack.ToArray());
    }
}
