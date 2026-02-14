# 🍾 Champagne Tower (LeetCode 799)

## 📝 Problem Summary

We stack glasses in a pyramid:
- Row 0 → 1 glass  
- Row 1 → 2 glasses  
- Row i → i + 1 glasses  

Each glass holds **exactly 1 cup** of champagne.

When champagne is poured:
- If a glass exceeds 1 cup,
- The extra amount (overflow) is equally distributed to:
  - Bottom-left glass
  - Bottom-right glass
- Excess at the last row is lost.

We must return how full the glass at:
(query_row, query_glass)
is after pouring `poured` cups.

---

## 💡 Approach — Dynamic Programming (Simulation)

### Key Observations

1. Each glass can hold **at most 1.0**.
2. Overflow is `(current_amount - 1) / 2`.
3. We simulate row by row until `query_row`.
4. Maximum row is < 100 → safe for O(n²) DP.

---

## 🧠 Algorithm Steps

1. Create a DP table `dp[row][col]`.
2. Initialize:
