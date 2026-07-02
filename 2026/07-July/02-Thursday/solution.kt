import java.util.ArrayDeque

class Solution {
    fun findSafeWalk(grid: List<List<Int>>, health: Int): Boolean {
        val m = grid.size
        val n = grid[0].size
        val dist = Array(m) { IntArray(n) { Int.MAX_VALUE } }
        val dirs = arrayOf(intArrayOf(0, 1), intArrayOf(1, 0), intArrayOf(0, -1), intArrayOf(-1, 0))
        
        val deque = ArrayDeque<IntArray>()
        dist[0][0] = grid[0][0]
        deque.offerFirst(intArrayOf(0, 0))
        
        while (deque.isNotEmpty()) {
            val curr = deque.pollFirst()!!
            val r = curr[0]
            val c = curr[1]
            
            if (r == m - 1 && c == n - 1) return health - dist[r][c] > 0
            
            for (d in dirs) {
                val nr = r + d[0]
                val nc = c + d[1]
                if (nr in 0 until m && nc in 0 until n) {
                    val w = grid[nr][nc]
                    if (dist[r][c] + w < dist[nr][nc]) {
                        dist[nr][nc] = dist[r][c] + w
                        if (w == 0) deque.offerFirst(intArrayOf(nr, nc))
                        else deque.offerLast(intArrayOf(nr, nc))
                    }
                }
            }
        }
        return false
    }
}
