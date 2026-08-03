class Solution {
    private Integer[] memo;
    private int[] stoneValue;
    private int n;

    public String stoneGameIII(int[] stoneValue) {
        this.stoneValue = stoneValue;
        this.n = stoneValue.length;
        this.memo = new Integer[n];

        int diff = dfs(0);

        if (diff > 0) {
            return "Alice";
        } else if (diff < 0) {
            return "Bob";
        } else {
            return "Tie";
        }
    }

    private int dfs(int i) {
        if (i >= n) {
            return 0;
        }

        if (memo[i] != null) {
            return memo[i];
        }

        int best = Integer.MIN_VALUE;
        int sum = 0;

        for (int j = i; j < Math.min(i + 3, n); j++) {
            sum += stoneValue[j];
            best = Math.max(best, sum - dfs(j + 1));
        }

        return memo[i] = best;
    }
}
