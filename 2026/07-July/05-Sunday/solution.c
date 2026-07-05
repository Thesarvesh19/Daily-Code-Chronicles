#define MOD 1000000007

int* pathsWithMaxScore(char** board, int boardSize, int* returnSize) {
    int n = boardSize;

    int score[105][105];
    int ways[105][105];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            score[i][j] = -1;
            ways[i][j] = 0;
        }

    score[n - 1][n - 1] = 0;
    ways[n - 1][n - 1] = 1;

    for (int i = n - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--) {

            if (board[i][j] == 'X') continue;
            if (i == n - 1 && j == n - 1) continue;

            int best = -1;
            long long cnt = 0;

            int dx[3] = {1, 0, 1};
            int dy[3] = {0, 1, 1};

            for (int k = 0; k < 3; k++) {
                int x = i + dx[k];
                int y = j + dy[k];

                if (x < n && y < n && score[x][y] != -1) {
                    if (score[x][y] > best) {
                        best = score[x][y];
                        cnt = ways[x][y];
                    } else if (score[x][y] == best) {
                        cnt = (cnt + ways[x][y]) % MOD;
                    }
                }
            }

            if (best == -1) continue;

            int val = (board[i][j] >= '0' && board[i][j] <= '9')
                          ? board[i][j] - '0'
                          : 0;

            score[i][j] = best + val;
            ways[i][j] = cnt % MOD;
        }
    }

    int* ans = (int*)malloc(sizeof(int) * 2);
    *returnSize = 2;

    if (ways[0][0] == 0) {
        ans[0] = 0;
        ans[1] = 0;
    } else {
        ans[0] = score[0][0];
        ans[1] = ways[0][0];
    }

    return ans;
}
