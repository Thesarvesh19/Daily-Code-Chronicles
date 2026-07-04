class Solution:
    def minScore(self, n: int, roads: List[List[int]]) -> int:
        graph = defaultdict(list)

        for u, v, d in roads:
            graph[u].append((v, d))
            graph[v].append((u, d))

        visited = set()
        ans = float('inf')

        def dfs(node):
            nonlocal ans
            visited.add(node)

            for nxt, dist in graph[node]:
                ans = min(ans, dist)
                if nxt not in visited:
                    dfs(nxt)

        dfs(1)
        return ans
