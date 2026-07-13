/**
 * @param {number[][]} grid
 * @return {boolean}
 */
var hasValidPath = function(grid) {
    const rows = grid.length;
    const cols = grid[0].length;

    const directions = {
        1: [[0, -1], [0, 1]],
        2: [[-1, 0], [1, 0]],
        3: [[0, -1], [1, 0]],
        4: [[0, 1], [1, 0]],
        5: [[0, -1], [-1, 0]],
        6: [[0, 1], [-1, 0]]
    };

    const opposite = {
        "0,-1": [0, 1],
        "0,1": [0, -1],
        "-1,0": [1, 0],
        "1,0": [-1, 0]
    };

    const visited = Array.from({ length: rows }, () => Array(cols).fill(false));
    const queue = [[0, 0]];
    visited[0][0] = true;

    while (queue.length) {
        const [x, y] = queue.shift();

        if (x === rows - 1 && y === cols - 1)
            return true;

        for (const [dx, dy] of directions[grid[x][y]]) {
            const nx = x + dx;
            const ny = y + dy;

            if (nx < 0 || ny < 0 || nx >= rows || ny >= cols)
                continue;

            if (visited[nx][ny])
                continue;

            const [bx, by] = opposite[`${dx},${dy}`];

            for (const [rx, ry] of directions[grid[nx][ny]]) {
                if (rx === bx && ry === by) {
                    visited[nx][ny] = true;
                    queue.push([nx, ny]);
                    break;
                }
            }
        }
    }

    return false;
};
