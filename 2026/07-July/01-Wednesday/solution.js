/**
 * @param {number[][]} grid
 * @return {number}
 */
var maximumSafenessFactor = function(grid) {
    const n = grid.length;
    
    // If start or end contains a thief, return 0
    if (grid[0][0] === 1 || grid[n - 1][n - 1] === 1) {
        return 0;
    }

    // Step 1: Multi-source BFS
    const distToThief = Array.from({ length: n }, () => Array(n).fill(-1));
    const q = [];
    let head = 0; // Using head pointer for O(1) queue shift operations

    for (let r = 0; r < n; r++) {
        for (let c = 0; c < n; c++) {
            if (grid[r][c] === 1) {
                q.push([r, c]);
                distToThief[r][c] = 0;
            }
        }
    }

    const directions = [[0, 1], [1, 0], [0, -1], [-1, 0]];

    while (head < q.length) {
        const [r, c] = q[head++];
        
        for (const [dr, dc] of directions) {
            const nr = r + dr;
            const nc = c + dc;
            
            if (nr >= 0 && nr < n && nc >= 0 && nc < n && distToThief[nr][nc] === -1) {
                distToThief[nr][nc] = distToThief[r][c] + 1;
                q.push([nr, nc]);
            }
        }
    }

    // Step 2: Modified Dijkstra using LeetCode's built-in MaxPriorityQueue
    const maxHeap = new MaxPriorityQueue({ priority: (x) => x.safeness });
    const visited = Array.from({ length: n }, () => Array(n).fill(false));

    maxHeap.enqueue({ safeness: distToThief[0][0], r: 0, c: 0 });
    visited[0][0] = true;

    while (!maxHeap.isEmpty()) {
        const { safeness: currentSafeness, r, c } = maxHeap.dequeue().element;

        // Reached destination
        if (r === n - 1 && c === n - 1) {
            return currentSafeness;
        }

        for (const [dr, dc] of directions) {
            const nr = r + dr;
            const nc = c + dc;
            
            if (nr >= 0 && nr < n && nc >= 0 && nc < n && !visited[nr][nc]) {
                visited[nr][nc] = true;
                const nextSafeness = Math.min(currentSafeness, distToThief[nr][nc]);
                maxHeap.enqueue({ safeness: nextSafeness, r: nr, c: nc });
            }
        }
    }

    return 0;
};
