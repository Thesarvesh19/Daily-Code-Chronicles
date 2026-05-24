# 1340. Jump Game V

## Problem
Given an array `arr` and integer `d`, you can jump from index `i` to:

- `i + x`
- `i - x`

where:

- `1 <= x <= d`
- `arr[j] < arr[i]`
- Cannot jump over an element greater than or equal to current value.

Return the maximum number of indices visited.

---

## Approach: DFS + Memoization

Use DFS to find maximum jumps from each index.

Store computed results using DP to avoid recalculation.

Steps:
1. Start DFS from every index.
2. Explore left and right up to distance `d`.
3. Stop when encountering higher/equal value.
4. Memoize result.

---

## Complexity

Time: `O(n × d)`

Space: `O(n)`

---

## Example

Input:
arr = [6,4,14,6,8,13,9,7,10,6,12]
d = 2

Output:
4
