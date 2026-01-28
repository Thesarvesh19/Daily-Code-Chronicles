class Solution {

    public int minCost(int[][] grid, int k) {
        int rows = grid.length;
        int cols = grid[0].length;
        int INF = Integer.MAX_VALUE / 2;

        int[][][] dp = new int[k + 1][rows][cols];

        for (int t = 0; t <= k; t++) {
            for (int i = 0; i < rows; i++) {
                Arrays.fill(dp[t][i], INF);
            }
        }

        // starting position
        dp[0][0][0] = 0;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (i > 0) {
                    dp[0][i][j] = Math.min(dp[0][i][j], dp[0][i - 1][j] + grid[i][j]);
                }
                if (j > 0) {
                    dp[0][i][j] = Math.min(dp[0][i][j], dp[0][i][j - 1] + grid[i][j]);
                }
            }
        }

        // group cells by their values
        Map<Integer, List<int[]>> valueToCells = new HashMap<>();
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                valueToCells
                    .computeIfAbsent(grid[i][j], v -> new ArrayList<>())
                    .add(new int[]{i, j});
            }
        }

        List<Integer> sortedValues = new ArrayList<>(valueToCells.keySet());
        sortedValues.sort(Collections.reverseOrder());

        // process teleport layers
        for (int t = 1; t <= k; t++) {

            int bestSoFar = INF;

            for (int value : sortedValues) {
                for (int[] cell : valueToCells.get(value)) {
                    bestSoFar = Math.min(bestSoFar, dp[t - 1][cell[0]][cell[1]]);
                }
                for (int[] cell : valueToCells.get(value)) {
                    dp[t][cell[0]][cell[1]] = bestSoFar;
                }
            }

            // normal moves after teleport
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    if (i > 0) {
                        dp[t][i][j] = Math.min(dp[t][i][j], dp[t][i - 1][j] + grid[i][j]);
                    }
                    if (j > 0) {
                        dp[t][i][j] = Math.min(dp[t][i][j], dp[t][i][j - 1] + grid[i][j]);
                    }
                }
            }
        }

       
        int answer = INF;
        for (int t = 0; t <= k; t++) {
            answer = Math.min(answer, dp[t][rows - 1][cols - 1]);
        }

        return answer;
    }
}
