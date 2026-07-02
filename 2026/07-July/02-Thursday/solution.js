/**
 * @param {number[][]} grid
 * @param {number} health
 * @return {boolean}
 */
var findSafeWalk = function(grid, health) {
    const m = grid.length;
    const n = grid[0].length;
    const dist = Array.from({ length: m }, () => Array(n).fill(Infinity));
    const dirs = [[0,1], [1,0], [0,-1], [-1,0]];
    
    let currQ = [];
    let nextQ = [];
    
    dist[0][0] = grid[0][0];
    if (grid[0][0] === 0) currQ.push([0, 0]);
    else nextQ.push([0, 0]);
    
    while (currQ.length > 0 || nextQ.length > 0) {
        if (currQ.length === 0) {
            currQ = nextQ;
            nextQ = [];
        }
        // pop() is O(1). Since weight is the same for the whole layer, order doesn't matter.
        const [r, c] = currQ.pop(); 
        
        if (r === m - 1 && c === n - 1) return health - dist[r][c] > 0;
        
        for (let [dr, dc] of dirs) {
            let nr = r + dr, nc = c + dc;
            if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
                let w = grid[nr][nc];
                if (dist[r][c] + w < dist[nr][nc]) {
                    dist[nr][nc] = dist[r][c] + w;
                    if (w === 0) currQ.push([nr, nc]);
                    else nextQ.push([nr, nc]);
                }
            }
        }
    }
    return false;
};
