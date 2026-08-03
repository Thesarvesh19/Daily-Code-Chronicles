# 1406. Stone Game III

## Overview
This repository contains an efficient solution for **LeetCode 1406 - Stone Game III**.

The solution uses **Dynamic Programming (Memoization)** to compute the maximum score difference the current player can achieve from each position. Since both players play optimally, the algorithm evaluates every possible move (taking 1, 2, or 3 stones) and chooses the one that maximizes the player's advantage.

---

## Approach

1. Define `dp(i)` as the maximum score difference the current player can obtain starting from index `i`.
2. At each position, consider taking:
   - 1 stone
   - 2 stones
   - 3 stones
3. Calculate the current sum of picked stones and subtract the opponent's best possible score difference:
   ```
   currentSum - dp(nextIndex)
   ```
4. Store computed results using memoization to avoid recomputation.
5. The value of `dp(0)` determines the winner:
   - `> 0` → Alice wins.
   - `< 0` → Bob wins.
   - `= 0` → Tie.

---

## Algorithm

- Use DFS with memoization.
- Explore all valid choices (1–3 stones).
- Compute the best possible score difference.
- Return the winner based on the final score difference.

---

## Complexity Analysis

- **Time Complexity:** `O(n)`
- **Space Complexity:** `O(n)`

where `n` is the number of stones.

---

## Topics

- Dynamic Programming
- Memoization
- Recursion
- Game Theory

---

## Languages

- Python
- Java
- C++

All implementations follow the same dynamic programming approach and are optimized to pass all LeetCode test cases.
