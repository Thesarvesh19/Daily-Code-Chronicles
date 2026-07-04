func minScore(n int, roads [][]int) int {
	graph := make([][][2]int, n+1)

	for _, road := range roads {
		u, v, d := road[0], road[1], road[2]
		graph[u] = append(graph[u], [2]int{v, d})
		graph[v] = append(graph[v], [2]int{u, d})
	}

	visited := make([]bool, n+1)
	ans := math.MaxInt

	var dfs func(int)
	dfs = func(node int) {
		visited[node] = true

		for _, edge := range graph[node] {
			next, dist := edge[0], edge[1]
			if dist < ans {
				ans = dist
			}
			if !visited[next] {
				dfs(next)
			}
		}
	}

	dfs(1)
	return ans
}
