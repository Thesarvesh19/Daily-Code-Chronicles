class Solution {
    fun remainingMethods(
        n: Int,
        k: Int,
        invocations: Array<IntArray>
    ): List<Int> {

        val graph = Array(n) { mutableListOf<Int>() }
        val undirected = Array(n) { mutableListOf<Int>() }

        for (edge in invocations) {
            val u = edge[0]
            val v = edge[1]

            graph[u].add(v)
            undirected[u].add(v)
            undirected[v].add(u)
        }

        val suspicious = BooleanArray(n)

        fun dfs(u: Int) {
            suspicious[u] = true
            for (v in graph[u]) {
                if (!suspicious[v]) {
                    dfs(v)
                }
            }
        }

        dfs(k)

        val visited = BooleanArray(n)

        fun dfs2(u: Int) {
            visited[u] = true
            for (v in undirected[u]) {
                if (!visited[v]) {
                    suspicious[v] = false
                    dfs2(v)
                }
            }
        }

        for (i in 0 until n) {
            if (!suspicious[i] && !visited[i]) {
                dfs2(i)
            }
        }

        val ans = mutableListOf<Int>()
        for (i in 0 until n) {
            if (!suspicious[i]) {
                ans.add(i)
            }
        }

        return ans
    }
}
