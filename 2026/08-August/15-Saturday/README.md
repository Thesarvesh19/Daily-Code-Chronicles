# LeetCode 3702 - Longest Subsequence With Non-Zero Bitwise XOR

## Approach

Calculate the XOR of all elements in the array.

There are three cases:

1. If the total XOR is non-zero, the entire array is valid, so return `n`.
2. If all elements are zero, no non-empty subsequence can have non-zero XOR, so return `0`.
3. If the total XOR is zero but at least one element is non-zero, remove one non-zero element. The remaining XOR becomes non-zero, so return `n - 1`.

## Complexity

- Time: O(n)
- Space: O(1)

## Python

```python
class Solution:
    def longestSubsequence(self, nums: List[int]) -> int:
        n = len(nums)
        xor = 0
        has_nonzero = False

        for x in nums:
            xor ^= x
            if x != 0:
                has_nonzero = True

        if xor != 0:
            return n

        if not has_nonzero:
            return 0

        return n - 1
