import java.util.*;

class Solution {
    public boolean canPartitionGrid(int[][] grid) {
        return check(grid) || check(transpose(grid));
    }

    private boolean check(int[][] g) {
        int m = g.length, n = g[0].length;

        long s1 = 0, s2 = 0;
        Map<Integer, Integer> cnt1 = new HashMap<>();
        Map<Integer, Integer> cnt2 = new HashMap<>();

        // total sum and count
        for (int[] row : g) {
            for (int x : row) {
                s2 += x;
                cnt2.put(x, cnt2.getOrDefault(x, 0) + 1);
            }
        }

        // try horizontal cuts
        for (int i = 0; i < m - 1; i++) {
            for (int x : g[i]) {
                s1 += x;
                s2 -= x;

                cnt1.put(x, cnt1.getOrDefault(x, 0) + 1);
                cnt2.put(x, cnt2.get(x) - 1);
            }

            if (s1 == s2) return true;

            if (s1 < s2) {
                long diff = s2 - s1;
                if (diff <= Integer.MAX_VALUE && cnt2.getOrDefault((int) diff, 0) > 0) {
                    if (
                        (m - i - 1 > 1 && n > 1) ||
                        (i == m - 2 && (g[i + 1][0] == diff || g[i + 1][n - 1] == diff)) ||
                        (n == 1 && (g[i + 1][0] == diff || g[m - 1][0] == diff))
                    ) {
                        return true;
                    }
                }
            } else {
                long diff = s1 - s2;
                if (diff <= Integer.MAX_VALUE && cnt1.getOrDefault((int) diff, 0) > 0) {
                    if (
                        (i + 1 > 1 && n > 1) ||
                        (i == 0 && (g[0][0] == diff || g[0][n - 1] == diff)) ||
                        (n == 1 && (g[0][0] == diff || g[i][0] == diff))
                    ) {
                        return true;
                    }
                }
            }
        }

        return false;
    }

    private int[][] transpose(int[][] grid) {
        int m = grid.length, n = grid[0].length;
        int[][] t = new int[n][m];

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                t[j][i] = grid[i][j];
            }
        }

        return t;
    }
}
