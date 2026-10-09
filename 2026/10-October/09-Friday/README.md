# LeetCode 1541 - Minimum Insertions to Balance a Parentheses String

## Problem Description
Given a parentheses string `s` containing only `'('` and `')'`, return the minimum number of insertions needed to make the string balanced.

A string is balanced if:
- Every opening parenthesis `'('` has exactly two consecutive closing parentheses `'))'`.
- The parentheses are properly matched.

## Approach: Greedy Algorithm

We use two variables:
- `ans`: Counts the minimum insertions required.
- `need`: Tracks the number of closing parentheses required to balance the string.

### Algorithm
1. Traverse the string from left to right.
2. If the current character is `'('`:
   - If `need` is odd, insert one `')'` to complete the previous pair.
   - Increase `need` by `2` for the current opening parenthesis.
3. If the current character is `')'`:
   - Decrease `need` by `1`.
   - If `need` becomes negative, insert `'('` and set `need` to `1`.
4. Return `ans + need`.

## Python Solution

```python
class Solution:
    def minInsertions(self, s: str) -> int:
        ans = 0
        need = 0

        for i in range(len(s)):
            if s[i] == '(':
                if need % 2 == 1:
                    ans += 1
                    need -= 1
                need += 2
            else:
                need -= 1

                if need < 0:
                    ans += 1
                    need = 1

        return ans + need
```

## Complexity Analysis

- **Time Complexity:** O(n), where n is the length of the string.
- **Space Complexity:** O(1), as only a constant number of variables are used.

## Key Takeaway
The greedy approach efficiently balances the parentheses by tracking the number of closing parentheses needed and inserting only those that are missing.

