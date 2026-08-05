func remainingMethods(n int, k int, invocations [][]int) []int {
	graph := make([][]int, n)
	undirected := make([][]int, n)

	for _, e := range invocations {
		u, v := e[0], e[1]
		graph[u] = append(graph[u], v)
		undirected[u] = append(undirected[u], v)
		undirected[v] = append(undirected[v], u)
	}

	suspicious := make([]bool, n)

	var dfs func(int)
	dfs = func(u int) {
		suspicious[u] = true
		for _, v := range graph[u] {
			if !suspicious[v] {
				dfs(v)
			}
		}
	}

	dfs(k)

	visited := make([]bool, n)

	var dfs2 func(int)
	dfs2 = func(u int) {
		visited[u] = true
		for _, v := range undirected[u] {
			if !visited[v] {
				suspicious[v] = false
				dfs2(v)
			}
		}
	}

	for i := 0; i < n; i++ {
		if !suspicious[i] && !visited[i] {
			dfs2(i)
		}
	}

	ans := []int{}
	for i := 0; i < n; i++ {
		if !suspicious[i] {
			ans = append(ans, i)
		}
	}

	return ans
}
