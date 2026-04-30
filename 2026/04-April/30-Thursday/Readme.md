# Maximum Path Score in a Grid

## Problem
Given a grid of integers and an integer k:

- Start at top-left (0,0)
- Reach bottom-right (m-1,n-1)
- Move only right or down
- You can include at most k positive cells (cost constraint)

## Approach
We use Dynamic Programming with space optimization.

### State
dp[j][c] = maximum score reaching column j using c cost

### Transition
- From top: dp[j][prev_c]
- From left: next_dp[j-1][prev_c]

### Cost
cost = 1 if value > 0 else 0

### Optimization
- Use rolling arrays (dp, next_dp)
- Reduce space from O(m*n*k) → O(n*k)

## Complexity
Time: O(m * n * k)  
Space: O(n * k)

## Languages
- Python
- Java
- C++
