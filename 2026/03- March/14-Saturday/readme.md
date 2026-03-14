# 1415. The k-th Lexicographical String of All Happy Strings of Length n

## Problem
A **happy string** is a string that:

- Consists only of characters `['a', 'b', 'c']`
- No two adjacent characters are the same 

Given integers `n` and `k`, return the **k-th happy string of length n in lexicographical order**.  
If fewer than `k` happy strings exist, return an empty string.

## Example

Input:
n = 3, k = 9

Output:
cab

Explanation:

All happy strings of length 3 in lexicographical order:


aba
abc
aca
acb
bab
bac
bca
bcb
cab
cac
cba
cbc


The 9th string is **"cab"**.

## Approach

We use **Backtracking (DFS)** to generate all valid happy strings.

Steps:
1. Start with an empty string.
2. Try adding characters `'a'`, `'b'`, `'c'`.
3. Skip characters equal to the previous character.
4. Stop when the string length becomes `n`.
5. Store results in lexicographical order.
6. Return the `k-1` index string if it exists.

Since `n ≤ 10`, the maximum number of happy strings is:

3 * 2^(n-1)

which is small enough for backtracking.

## Complexity

Time Complexity:  
O(2^n)

Space Complexity:  
O(2^n)

## Python Implementation

```python
class Solution:
    def getHappyString(self, n: int, k: int) -> str:
        result = []

        def backtrack(current: str):
            if len(result) >= k:
                return

            if len(current) == n:
                result.append(current)
                return

            for ch in ['a', 'b', 'c']:
                if not current or current[-1] != ch:
                    backtrack(current + ch)

        backtrack("")

        if k <= len(result):
            return result[k - 1]
        return ""

---
