/**
 * @param {string[]} board
 * @return {number[]}
 */
var pathsWithMaxScore = function(board) {
    const MOD = 1000000007;
    const n = board.length;

    const score = Array.from({ length: n }, () => Array(n).fill(-1));
    const ways = Array.from({ length: n }, () => Array(n).fill(0));

    score[n - 1][n - 1] = 0;
    ways[n - 1][n - 1] = 1;

    const dirs = [[1, 0], [0, 1], [1, 1]];

    for (let i = n - 1; i >= 0; i--) {
        for (let j = n - 1; j >= 0; j--) {

            if (board[i][j] === 'X') continue;
            if (i === n - 1 && j === n - 1) continue;

            let best = -1;
            let count = 0;

            for (const [dx, dy] of dirs) {
                const x = i + dx;
                const y = j + dy;

                if (x < n && y < n && score[x][y] !== -1) {
                    if (score[x][y] > best) {
                        best = score[x][y];
                        count = ways[x][y];
                    } else if (score[x][y] === best) {
                        count = (count + ways[x][y]) % MOD;
                    }
                }
            }

            if (best === -1) continue;

            const ch = board[i][j];
            const val = /\d/.test(ch) ? Number(ch) : 0;

            score[i][j] = best + val;
            ways[i][j] = count;
        }
    }

    if (ways[0][0] === 0) {
        return [0, 0];
    }

    return [score[0][0], ways[0][0]];
};
