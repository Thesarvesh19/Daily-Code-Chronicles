# LeetCode 3693 - Climbing Stairs II

## Problem
**Difficulty:** Medium  
**Topics:** Dynamic Programming  
**Language:** Python 3

## Approach: Dynamic Programming

We use Dynamic Programming to find the minimum cost required to reach the top of the staircase.

At each step, we can jump either 1, 2, or 3 stairs. The jumping costs are the squares of the jump lengths:

- Jump 1 stair: Cost = 1
- Jump 2 stairs: Cost = 4
- Jump 3 stairs: Cost = 9

We maintain a DP array where `dp[i]` represents the minimum cost required to reach stair `i`.

### Python Solution

```python
class Solution:
    def climbStairs(self, n: int, costs: List[int]) -> int:
        dp = [0] * (n + 1)

        for i in range(1, n + 1):
            dp[i] = min(
                dp[i - 1] + 1,
                dp[i - 2] + 4 if i >= 2 else float('inf'),
                dp[i - 3] + 9 if i >= 3 else float('inf')
            ) + costs[i - 1]

        return dp[n]
```

## Complexity Analysis

- **Time Complexity:** O(n) – We iterate through the staircase once.
- **Space Complexity:** O(n) – We use a DP array of size n + 1.

## Key Takeaways

- Apply Dynamic Programming to minimize the total cost.
- Consider all three possible jump lengths.
- Store previously calculated minimum costs to avoid redundant computations.

## Problem Link

[LeetCode 3693 - Climbing Stairs II](https://leetcode.com/problems/climbing-stairs-ii/)
