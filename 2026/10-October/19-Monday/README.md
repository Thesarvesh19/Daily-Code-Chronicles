# 2089. Find Target Indices After Sorting Array

## Problem Statement
You are given a 0-indexed integer array `nums` and an integer `target`. Return a list of indices where `target` appears after sorting `nums` in non-decreasing order.

If `target` does not appear in the array, return an empty list.

## Approach: Sorting + Linear Search

1. Sort the array in ascending order.
2. Traverse the sorted array using `enumerate()`.
3. Store the indices where the element equals `target`.
4. Return the list of matching indices.

## Python Solution

```python
class Solution:
    def targetIndices(self, nums: list[int], target: int) -> list[int]:
        nums.sort()
        return [i for i, x in enumerate(nums) if x == target]
```

## Example

**Input:**
```text
nums = [1, 2, 5, 2, 3]
target = 2
```

**Output:**
```text
[1, 2]
```

**Explanation:**

After sorting, the array becomes `[1, 2, 2, 3, 5]`. The target `2` appears at indices `1` and `2`.

## Complexity Analysis

- **Time Complexity:** `O(n log n)` due to sorting.
- **Auxiliary Space Complexity:** `O(log n)` typically for Python's sorting implementation, excluding the output list.

## Key Takeaway
Sorting places equal elements together, making it easy to find all indices of the target in the sorted array.
