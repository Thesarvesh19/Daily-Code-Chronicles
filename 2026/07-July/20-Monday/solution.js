/**
 * @param {number[][]} grid
 * @param {number} k
 * @return {number[][]}
 */
var shiftGrid = function (grid, k) {
    const rows = grid.length;
    const cols = grid[0].length;
    const total = rows * cols;

    k %= total;

    const shifted = Array.from(
        { length: rows },
        () => Array(cols).fill(0)
    );

    for (let r = 0; r < rows; r++) {
        for (let c = 0; c < cols; c++) {

            const current = r * cols + c;
            const target = (current + k) % total;

            const nr = Math.floor(target / cols);
            const nc = target % cols;

            shifted[nr][nc] = grid[r][c];
        }
    }

    return shifted;
};
