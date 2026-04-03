import java.util.*;

class Solution {
    private Integer[][] dp;
    private int[][] robotData;
    private int[] walls;
    private int n;

    public int maxWalls(int[] robots, int[] distance, int[] walls) {
        n = robots.length;

        robotData = new int[n][2];
        for (int i = 0; i < n; i++) {
            robotData[i][0] = robots[i];
            robotData[i][1] = distance[i];
        }

        Arrays.sort(robotData, Comparator.comparingInt(a -> a[0]));
        Arrays.sort(walls);
        this.walls = walls;

        dp = new Integer[n][2];

        return dfs(n - 1, 1);
    }

    private int dfs(int i, int nextRight) {
        if (i < 0) return 0;

        if (dp[i][nextRight] != null) return dp[i][nextRight];

        int pos = robotData[i][0];
        int dist = robotData[i][1];

        // Left
        int leftBoundary = pos - dist;
        if (i > 0) {
            leftBoundary = Math.max(leftBoundary, robotData[i - 1][0] + 1);
        }

        int l = lowerBound(walls, leftBoundary);
        int r = lowerBound(walls, pos + 1);
        int resLeft = dfs(i - 1, 0) + (r - l);

        // Right
        int rightBoundary = pos + dist;
        if (i + 1 < n) {
            int nextPos = robotData[i + 1][0];
            int nextDist = robotData[i + 1][1];

            if (nextRight == 0) {
                rightBoundary = Math.min(rightBoundary, nextPos - nextDist - 1);
            } else {
                rightBoundary = Math.min(rightBoundary, nextPos - 1);
            }
        }

        int resRight;
        if (rightBoundary < pos) {
            resRight = dfs(i - 1, 1);
        } else {
            l = lowerBound(walls, pos);
            r = lowerBound(walls, rightBoundary + 1);
            resRight = dfs(i - 1, 1) + (r - l);
        }

        return dp[i][nextRight] = Math.max(resLeft, resRight);
    }

    private int lowerBound(int[] arr, int target) {
        int l = 0, r = arr.length;
        while (l < r) {
            int m = (l + r) / 2;
            if (arr[m] < target) l = m + 1;
            else r = m;
        }
        return l;
    }
}
