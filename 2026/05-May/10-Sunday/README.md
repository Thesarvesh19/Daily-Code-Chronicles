# 2770. Maximum Number of Jumps to Reach the Last Index

## Problem Statement

You are given a 0-indexed integer array `nums` and an integer `target`.

You are initially positioned at index `0`.  
In one step, you can jump from index `i` to index `j` if:

- `i < j`
- `abs(nums[j] - nums[i]) <= target`

Return the maximum number of jumps needed to reach the last index.

If it is not possible to reach the last index, return `-1`.

---

## Example

### Input
```txt
nums = [1,3,6,4,1,2]
target = 2
Output
3
Explanation

One possible path is:

0 → 1 → 3 → 5

So the maximum number of jumps is 3.

Approach

We use Dynamic Programming.

dp[i] stores the maximum jumps required to reach index i.
Initialize all values with -1.
Start with dp[0] = 0.
For every pair (i, j) where i < j:
If the jump condition is valid,
update:
dp[j] = max(dp[j], dp[i] + 1)
Finally return dp[n-1].
Complexity Analysis
Time Complexity: O(n²)
Space Complexity: O(n)
