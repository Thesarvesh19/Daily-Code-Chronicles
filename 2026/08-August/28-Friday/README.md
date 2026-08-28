# LeetCode 3734 — Lexicographically Smallest Palindromic Permutation Greater Than Target

## Problem

Given a string `s` and a string `target`, find the **lexicographically smallest palindromic permutation of `s` that is strictly greater than `target`**.

If no such palindrome exists, return an empty string `""`.

---

## Approach

A palindrome is completely determined by its left half and its middle character.

For example:

```text
s = "aabb"

Left half = "ab"

Palindrome:
ab + ba = "abba"
```

If the length is odd, one character appears in the middle.

### Steps

1. Count the frequency of every character in `s`.
2. Check whether a palindrome can be formed.

   * A palindrome can have **at most one character with an odd frequency**.
   * If more than one character has an odd frequency, return `""`.
3. Construct the character counts for the left half.
4. Build the left half from left to right.
5. At every position:

   * Try characters from `'a'` to `'z'`.
   * Temporarily place the smallest available character.
   * Fill the remaining positions with the largest possible characters.
   * Construct the complete palindrome.
   * If it is strictly greater than `target`, keep the character.
   * Otherwise, undo the choice and try the next character.
6. Return the resulting palindrome.

---

## Why Greedy Works

We want the **smallest** palindrome that is greater than `target`.

Therefore, at each position we try the smallest possible character first.

However, simply choosing the smallest character is not enough. We must make sure that the remaining characters can still produce a palindrome greater than `target`.

To check this, after choosing a character we construct the **largest possible completion**.

If even that largest completion is not greater than `target`, then the current choice can never produce a valid answer.

Otherwise, the choice is safe and gives the lexicographically smallest possible result.

---

## Example

```text
s = "aabb"
target = "abbb"
```

The possible palindromic permutations are:

```text
abba
baab
```

Since:

```text
abba > abbb
```

is false, while:

```text
baab > abbb
```

is true,

the answer is:

```text
baab
```

---

## C# Implementation

```csharp
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

                // Fill remaining positions with the largest characters.
                string remaining = "";

                for (int x = 25; x >= 0; x--)
                {
                    if (half[x] > 0)
                        remaining += new string((char)('a' + x), half[x]);
                }

                string candidateLeft = left + remaining;
                string candidate = BuildPalindrome(candidateLeft);

                if (string.Compare(
                        candidate,
                        target,
                        StringComparison.Ordinal) > 0)
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

        return string.Compare(
                   answer,
                   target,
                   StringComparison.Ordinal) > 0
            ? answer
            : "";
    }
}
```

---

## Complexity Analysis

Let `n` be the length of `s`.

### Time Complexity

At every position of the left half, we may try up to `26` characters and construct a completion of length `O(n)`.

Therefore:

```text
O(26 × n²)
```

Since the alphabet size is fixed at 26:

```text
O(n²)
```

### Space Complexity

We store the left half and temporary strings:

```text
O(n)
```

---

## Key Insight

The important observation is:

> A palindrome is completely determined by its left half and its middle character.

Therefore, instead of generating all permutations, we only need to construct the left half greedily while checking whether a valid larger palindrome can still be formed.

This reduces the problem from potentially factorial permutation generation to a polynomial-time greedy solution.
