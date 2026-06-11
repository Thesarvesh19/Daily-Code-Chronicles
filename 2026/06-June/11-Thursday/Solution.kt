class Solution {
    private val MOD = 1_000_000_007L

    private fun modPow(a: Long, b: Long): Long {
        var base = a
        var exp = b
        var res = 1L

        while (exp > 0) {
            if ((exp and 1L) == 1L) {
                res = (res * base) % MOD
            } 

            base = (base * base) % MOD
            exp = exp shr 1
        }

        return res
    }

    fun assignEdgeWeights(edges: Array<IntArray>): Int {
        val n = edges.size + 1

        val graph = Array(n + 1) { mutableListOf<Int>() }

        for (e in edges) {
            graph[e[0]].add(e[1])
            graph[e[1]].add(e[0])
        }

        val q = ArrayDeque<Int>()
        val vis = BooleanArray(n + 1)

        q.addLast(1)
        vis[1] = true

        var depth = -1

        while (q.isNotEmpty()) {
            var sz = q.size
            depth++

            repeat(sz) {
                val u = q.removeFirst()

                for (v in graph[u]) {
                    if (!vis[v]) {
                        vis[v] = true
                        q.addLast(v)
                    }
                }
            }
        }

        return modPow(2, (depth - 1).toLong()).toInt()
    }
}
