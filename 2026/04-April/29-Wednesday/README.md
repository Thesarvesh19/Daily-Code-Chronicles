# 3225. Maximum Score From Grid Operations

## Problem Summary

You are given an `n x n` grid. You can choose a number of cells from each column such that:

- You pick cells from top to bottom in each column.
- The number of selected cells in adjacent columns affects the score.

Your goal is to **maximize the total score**.

---

## Approach

We use **Dynamic Programming + Prefix Sum**.

### Key Ideas

1. **Prefix Sum**
   - Precompute column-wise prefix sums.
   - Helps in calculating range sums in O(1).

2. **DP States**
   - `prevPick[i]`: max score till previous column when last picked row is `i-1`.
   - `prevSkip[i]`: max score when previous column is skipped relative to earlier state.

3. **Transition**
   For each column:
   - Try all combinations of previous and current selected rows.
   - Two cases:
     - `curr > prev`: extend downward → gain from previous column.
     - `curr <= prev`: move upward → gain from current column.

4. **Answer**
   - Maximum value in final `prevPick`.

---

## Code (Java)

```java
import java.util.*;

class Solution {
  public long maximumScore(int[][] grid) {
    final int n = grid.length;

    long[][] prefix = new long[n][n + 1];
    long[] prevPick = new long[n + 1];
    long[] prevSkip = new long[n + 1];

    for (int j = 0; j < n; ++j)
      for (int i = 0; i < n; ++i)
        prefix[j][i + 1] = prefix[j][i] + grid[i][j];

    for (int j = 1; j < n; ++j) {
      long[] currPick = new long[n + 1];
      long[] currSkip = new long[n + 1];

      for (int curr = 0; curr <= n; ++curr)
        for (int prev = 0; prev <= n; ++prev)
          if (curr > prev) {
            final long score = prefix[j - 1][curr] - prefix[j - 1][prev];
            currPick[curr] = Math.max(currPick[curr], prevSkip[prev] + score);
            currSkip[curr] = Math.max(currSkip[curr], prevSkip[prev] + score);
          } else {
            final long score = prefix[j][prev] - prefix[j][curr];
            currPick[curr] = Math.max(currPick[curr], prevPick[prev] + score);
            currSkip[curr] = Math.max(currSkip[curr], prevPick[prev]);
          }

      prevPick = currPick;
      prevSkip = currSkip;
    }

    return Arrays.stream(prevPick).max().getAsLong();
  }
}
