# LeetCode 3644 - Maximum K to Sort a Permutation

## Problem Description

You are given a permutation `nums` of integers from `0` to `n - 1`. Find the maximum non-negative integer `k` such that you can sort the permutation by repeatedly swapping elements whose bitwise AND with `k` satisfies the operation's requirements.

## Approach: Bit Manipulation

1. Initialize `ans = -1`.
2. Traverse the array using `enumerate()` to obtain each index and its corresponding value.
3. If an element `nums[i]` is not equal to its index `i`, update `ans` using bitwise AND.
4. Return `max(ans, 0)` to handle the already-sorted permutation.

## Python Solution

```python
class Solution:
    def sortPermutation(self, nums: list[int]) -> int:
        ans = -1

        for i, num in enumerate(nums):
            if num != i:
                ans &= num

        return max(ans, 0)
```

## Complexity Analysis

- **Time Complexity:** O(n), where `n` is the length of `nums`.
- **Space Complexity:** O(1), as the algorithm uses only a constant amount of extra space.

## Example

**Input:**
```text
nums = [0, 3, 2, 1]
```

**Output:**
```text
1
```

**Explanation:** The elements `3` and `1` are misplaced. Their bitwise AND is `3 & 1 = 1`, giving the answer `1`.

## Key Concepts

- Bitwise AND (`&`)
- Array Traversal
- Permutations
- Time and Space Complexity
