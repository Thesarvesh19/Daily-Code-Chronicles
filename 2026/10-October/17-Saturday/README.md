
# LeetCode 3551 - Minimum Swaps to Sort by Digit Sum

## Problem
Find the minimum number of swaps required to sort the array in ascending order based on the digit sum of each number. If two numbers have the same digit sum, sort them by their numerical values.

## Approach
1. Calculate the digit sum of each number.
2. Sort the array using digit sum as the primary key and the number itself as the secondary key.
3. Create a mapping of each number to its target index.
4. Use cycle detection to count the minimum swaps required.
5. A cycle of size `k` requires `k - 1` swaps.

## Python Solution

```python
class Solution:
    def minSwaps(self, nums: List[int]) -> int:
        def digit_sum(x):
            return sum(int(d) for d in str(x))

        sorted_nums = sorted(nums, key=lambda x: (digit_sum(x), x))
        position = {num: i for i, num in enumerate(sorted_nums)}

        n = len(nums)
        visited = [False] * n
        swaps = 0

        for i in range(n):
            if visited[i]:
                continue

            j = i
            cycle_size = 0

            while not visited[j]:
                visited[j] = True
                j = position[nums[j]]
                cycle_size += 1

            if cycle_size > 1:
                swaps += cycle_size - 1

        return swaps
```

## Example

**Input:**
```text
nums = [18, 43, 34, 16]
```

**Output:**
```text
2
```

**Explanation:**

The sorted array is `[16, 34, 43, 18]`. The minimum number of swaps required to achieve this order is `2`.

## Complexity Analysis

- **Time Complexity:** `O(n log n)` for sorting and `O(n)` for cycle detection.
- **Space Complexity:** `O(n)` for the sorted array, position mapping, and visited array.

## Key Concepts
- Sorting with a custom key
- Digit sum calculation
- Hash maps
- Cycle detection
- Minimum swaps
- Python programming
