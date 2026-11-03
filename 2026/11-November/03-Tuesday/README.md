
# LeetCode 3736 - Minimum Moves to Equal Array Elements III

## Problem
Given an integer array `nums`, determine the minimum number of moves required to make all elements equal by increasing elements.

## Approach: Greedy / Mathematics

1. Find the maximum element in the array.
2. Treat the maximum element as the target value.
3. Calculate the difference between the target and every element.
4. Return the sum of all differences.

### Python Solution

```python
class Solution:
    def minMoves(self, nums: List[int]) -> int:
        return max(nums) * len(nums) - sum(nums)
```

## Example

**Input:**
```text
nums = [2, 1, 3]
```

**Output:**
```text
3
```

**Explanation:**

The maximum element is `3`.

Required moves:
- `2` → `3`: 1 move
- `1` → `3`: 2 moves
- `3` → `3`: 0 moves

Total moves = `1 + 2 + 0 = 3`.

## Complexity Analysis

- **Time Complexity:** O(n) – Finding the maximum and calculating the sum.
- **Space Complexity:** O(1) – Constant extra space.

## Key Concepts
- Arrays
- Greedy Algorithm
- Mathematics

## Language
- Python 3

---

**Author:** Sarvesh
**Platform:** LeetCode
**Problem Number:** 3736
