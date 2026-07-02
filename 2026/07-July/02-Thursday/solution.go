func findSafeWalk(grid [][]int, health int) bool {
    m, n := len(grid), len(grid[0])
    dist := make([][]int, m)
    for i := range dist {
        dist[i] = make([]int, n)
        for j := range dist[i] {
            dist[i][j] = 1e9
        }
    }
    
    dirs := [][]int{{0, 1}, {1, 0}, {0, -1}, {-1, 0}}
    
    var currQ, nextQ [][]int
    
    dist[0][0] = grid[0][0]
    if grid[0][0] == 0 {
        currQ = append(currQ, []int{0, 0})
    } else {
        nextQ = append(nextQ, []int{0, 0})
    }
    
    for len(currQ) > 0 || len(nextQ) > 0 {
        if len(currQ) == 0 {
            currQ = nextQ
            nextQ = [][]int{}
        }
        
        curr := currQ[len(currQ)-1]
        currQ = currQ[:len(currQ)-1]
        r, c := curr[0], curr[1]
        
        if r == m-1 && c == n-1 {
            return health - dist[r][c] > 0
        }
        
        for _, d := range dirs {
            nr, nc := r+d[0], c+d[1]
            if nr >= 0 && nr < m && nc >= 0 && nc < n {
                w := grid[nr][nc]
                if dist[r][c]+w < dist[nr][nc] {
                    dist[nr][nc] = dist[r][c]+w
                    if w == 0 {
                        currQ = append(currQ, []int{nr, nc})
                    } else {
                        nextQ = append(nextQ, []int{nr, nc})
                    }
                }
            }
        }
    }
    return false
}
