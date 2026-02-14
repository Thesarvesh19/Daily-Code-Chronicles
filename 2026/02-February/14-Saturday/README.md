# Champagne Tower (LC 799)

##  Problem Summary

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

##  Approach — Dynamic Programming (Simulation)

### Key Observations

1. Each glass can hold **at most 1.0**.
2. Overflow is `(current_amount - 1) / 2`.
3. We simulate row by row until `query_row`.
4. Maximum row is < 100 → safe for O(n²) DP.

---

##  Algorithm Steps

dp[0][0] = poured

3. For each row:
- If `dp[r][c] > 1`
- Compute overflow
- Distribute equally to next row
- Cap current glass to 1
4. Return:


min(1, dp[query_row][query_glass])


---

## ⏱ Complexity Analysis

| Type | Complexity |
|------|------------|
| Time | O(row²) |
| Space | O(row²) |

Since `row < 100`, worst-case operations ≈ 5000 → extremely fast.

---

#  Python Implementation

```python
class Solution:
 def champagneTower(self, poured, query_row, query_glass):
     dp = [[0.0] * (r + 1) for r in range(query_row + 1)]
     dp[0][0] = poured

     for r in range(query_row):
         for c in range(len(dp[r])):
             if dp[r][c] > 1:
                 overflow = (dp[r][c] - 1) / 2.0
                 dp[r + 1][c] += overflow
                 dp[r + 1][c + 1] += overflow
                 dp[r][c] = 1.0

     return min(1.0, dp[query_row][query_glass])

 Java Implementation
class Solution {
    public double champagneTower(int poured, int query_row, int query_glass) {
        double[][] dp = new double[query_row + 1][query_row + 1];
        dp[0][0] = poured;

        for (int r = 0; r < query_row; r++) {
            for (int c = 0; c <= r; c++) {
                if (dp[r][c] > 1.0) {
                    double overflow = (dp[r][c] - 1.0) / 2.0;
                    dp[r + 1][c] += overflow;
                    dp[r + 1][c + 1] += overflow;
                    dp[r][c] = 1.0;
                }
            }
        }

        return Math.min(1.0, dp[query_row][query_glass]);
    }
}

 C Implementation
#include <stdlib.h>

double champagneTower(int poured, int query_row, int query_glass) {
    double dp[101][101] = {0};
    dp[0][0] = poured;

    for (int r = 0; r < query_row; r++) {
        for (int c = 0; c <= r; c++) {
            if (dp[r][c] > 1.0) {
                double overflow = (dp[r][c] - 1.0) / 2.0;
                dp[r + 1][c] += overflow;
                dp[r + 1][c + 1] += overflow;
                dp[r][c] = 1.0;
            }
        }
    }

    if (dp[query_row][query_glass] > 1.0)
        return 1.0;

    return dp[query_row][query_glass];
}

 Why This Works

Handles very large poured values (up to 10⁹)

Prevents overflow errors

Caps each glass correctly at 1

Matches LeetCode function signatures exactly

 Example

Input:

poured = 2
query_row = 1
query_glass = 1


Output:

0.5


1. Create a DP table `dp[row][col]`.
2. Initialize:
