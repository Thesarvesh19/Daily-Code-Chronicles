
# 462. Minimum Moves to Equal Array Elements II

## Problem
Given an integer array `nums`, return the minimum number of moves required to make all array elements equal.

In one move, you can increment or decrement an element by 1.

## Approach: Sorting + Median

The optimal solution uses the mathematical property of the median.

1. Sort the given array.
2. Select the middle element as the median.
3. Calculate the absolute difference between every element and the median.
4. Return the sum of all absolute differences.

The median minimizes the sum of absolute differences, making it the optimal target value.

## C++ Solution

```cpp
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int median = nums[nums.size() / 2];
        int moves = 0;

        for (int num : nums) {
            moves += abs(num - median);
        }

        return moves;
    }
};
```

## Example

**Input:**
```text
nums = [1, 2, 3]
```

**Output:**
```text
2
```

**Explanation:**

The median of the array is `2`.

- 1 → 2: 1 move
- 2 → 2: 0 moves
- 3 → 2: 1 move

Total moves = 1 + 0 + 1 = 2.

## Complexity Analysis

| Complexity | Value | Explanation |
|---|---|---|
| Time | O(n log n) | Sorting the array |
| Auxiliary Space | O(1) | Constant extra space, excluding sorting overhead |

## Key Concepts

- Arrays
- Sorting
- Mathematics
- Median
- Greedy Approach

## LeetCode Details

- **Problem Number:** 462
- **Problem Name:** Minimum Moves to Equal Array Elements II
- **Difficulty:** Medium
- **Language:** C++
- **Approach:** Sorting + Median

---
**Optimal Solution | LeetCode 462**
