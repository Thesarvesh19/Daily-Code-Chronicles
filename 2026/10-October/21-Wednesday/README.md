# LeetCode 3863 — Python Solution

## Problem
**3863. Minimum Operations to Sort a String**

## Approach
The solution checks whether the string is already sorted. If it is, the answer is `0`. Otherwise, it uses the positions of the minimum and maximum characters to determine the minimum number of operations required.

## Python Solution

```python
class Solution:
    def minOperations(self, s: str) -> int:
        n = len(s)

        if all(s[i] <= s[i + 1] for i in range(n - 1)):
            return 0

        if n == 2:
            return -1

        mn = min(s)
        mx = max(s)

        if s[0] == mn or s[-1] == mx:
            return 1

        if mn in s[1:-1] or mx in s[1:-1]:
            return 2

        return 3
```

## Complexity Analysis

- **Time Complexity:** `O(n)`
- **Space Complexity:** `O(1)` auxiliary space.

## Key Takeaway
Checking whether the string is sorted and locating its minimum and maximum characters helps determine the required operations efficiently.

## Language
Python 3
