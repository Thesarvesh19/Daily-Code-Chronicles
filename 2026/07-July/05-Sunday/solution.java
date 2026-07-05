class Solution {
    public int[] pathsWithMaxScore(List<String> board) {
        final int MOD = 1_000_000_007;
        int n = board.size();

        int[][] score = new int[n][n];
        int[][] ways = new int[n][n];

        for (int i = 0; i < n; i++) {
            Arrays.fill(score[i], -1);
        }

        score[n - 1][n - 1] = 0;
        ways[n - 1][n - 1] = 1;

        int[][] dirs = {{1, 0}, {0, 1}, {1, 1}};

        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {

                if (board.get(i).charAt(j) == 'X') continue;
                if (i == n - 1 && j == n - 1) continue;

                int best = -1;
                long count = 0;

                for (int[] d : dirs) {
                    int x = i + d[0];
                    int y = j + d[1];

                    if (x < n && y < n && score[x][y] != -1) {
                        if (score[x][y] > best) {
                            best = score[x][y];
                            count = ways[x][y];
                        } else if (score[x][y] == best) {
                            count = (count + ways[x][y]) % MOD;
                        }
                    }
                }

                if (best == -1) continue;

                char ch = board.get(i).charAt(j);
                int val = Character.isDigit(ch) ? ch - '0' : 0;

                score[i][j] = best + val;
                ways[i][j] = (int) (count % MOD);
            }
        }

        if (ways[0][0] == 0) {
            return new int[]{0, 0};
        }

        return new int[]{score[0][0], ways[0][0]};
    }
}
