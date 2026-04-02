# Maximum Coins with Robber Neutralization

##  Problem

You are given a grid `coins` of size `m x n`.

- Start from `(0, 0)` and reach `(m - 1, n - 1)`
- You can only move **right** or **down**

Each cell contains:
- Positive value → gain coins
- Negative value → robber steals coins

You can **neutralize at most 2 robbers**, meaning you avoid losing coins in those cells.

Return the **maximum coins** you can collect.

---

##  Approach

We use **Dynamic Programming (DP)** with an extra dimension.

### State Definition


dp[i][j][k]


- `i, j` → current position
- `k` → number of neutralizations used (0 to 2)

Represents the **maximum coins collected** at `(i, j)`.

---

##  Transition

From top `(i-1, j)` or left `(i, j-1)`:

### 1. Normal move
Add the cell value:


dp[i][j][k] = previous + coins[i][j]


### 2. Neutralize robber (if negative and k < 2)


dp[i][j][k+1] = previous (no loss)


---

##  Initialization

At `(0,0)`:

- If positive → take value
- If negative:
  - take loss
  - or neutralize (use 1)

---

##  Result


max(dp[m-1][n-1][0], dp[m-1][n-1][1], dp[m-1][n-1][2])


---

##  Complexity

- Time: `O(m * n * 3)`
- Space: `O(m * n * 3)`

---

##  Key Insight

This is a **grid DP with limited resource (k = 2)** problem.

Similar patterns:
- k obstacle removals
- k skips in path
- constrained shortest path

---

##  Example

### Input

coins = [[0,1,-1],
[1,-2,3],
[2,-3,4]]


### Output

8
