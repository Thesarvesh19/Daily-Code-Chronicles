public class Solution {
    public int[] PathsWithMaxScore(IList<string> board) {
        int MOD = 1000000007;
        int n = board.Count;

        int[,] score = new int[n, n];
        int[,] ways = new int[n, n];

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                score[i, j] = -1;

        score[n - 1, n - 1] = 0;
        ways[n - 1, n - 1] = 1;

        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {

                if (board[i][j] == 'X') continue;
                if (i == n - 1 && j == n - 1) continue;

                int best = -1;
                long cnt = 0;

                int[][] dir = {
                    new int[]{1,0},
                    new int[]{0,1},
                    new int[]{1,1}
                };

                foreach (var d in dir) {
                    int x = i + d[0];
                    int y = j + d[1];

                    if (x < n && y < n && score[x,y] != -1) {
                        if (score[x,y] > best) {
                            best = score[x,y];
                            cnt = ways[x,y];
                        } else if (score[x,y] == best) {
                            cnt = (cnt + ways[x,y]) % MOD;
                        }
                    }
                }

                if (best == -1) continue;

                int val = Char.IsDigit(board[i][j]) ? board[i][j] - '0' : 0;

                score[i,j] = best + val;
                ways[i,j] = (int)(cnt % MOD);
            }
        }

        if (ways[0,0] == 0)
            return new int[]{0,0};

        return new int[]{score[0,0], ways[0,0]};
    }
}
