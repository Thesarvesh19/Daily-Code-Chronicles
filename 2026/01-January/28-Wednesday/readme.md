# Minimum Cost Path with Teleportation

This project solves a grid pathfinding problem where you can move normally
or use limited teleportation to reduce cost.

## 🧩 Problem Summary

- You are given a 2D grid of integers.
- You start from the top-left cell `(0,0)`.
- You want to reach the bottom-right cell.
- Each move **right or down** adds the cost of the destination cell.
- You can **teleport at most `k` times**:
  - Teleport from any cell to any other cell with **value ≤ current cell**
  - Teleport cost is **0**

The goal is to find the **minimum total cost**.

---

## 💡 Approach (Simple Explanation)

- We use **Dynamic Programming**.
- `dp[t][i][j]` stores the minimum cost to reach cell `(i, j)` using `t` teleports.
- For each teleport layer:
  1. First apply **teleport transitions** (processed by cell values in descending order)
  2. Then apply **normal right and down moves**

This ensures teleport rules are applied correctly without breaking path order.

---

## ⏱️ Complexity

- **Time:** `O(k × m × n)`
- **Space:** `O(k × m × n)`

Works efficiently within the given constraints.

---

## ✅ Result

- Handles all edge cases
- Passes all test cases
- Editorial-safe and reliable

---

## 📂 Files

- `Solution.java` → main implementation
