from typing import List

class Solution:
    def remainingMethods(self, n: int, k: int, invocations: List[List[int]]) -> List[int]:
        graph = [[] for _ in range(n)]
        undirected = [[] for _ in range(n)]

        for u, v in invocations:
            graph[u].append(v)
            undirected[u].append(v)
            undirected[v].append(u)

        suspicious = [False] * n

        def dfs(node):
            suspicious[node] = True
            for nxt in graph[node]:
                if not suspicious[nxt]:
                    dfs(nxt)

        dfs(k)

        visited = [False] * n

        def dfs2(node):
            visited[node] = True
            for nxt in undirected[node]:
                if not visited[nxt]:
                    suspicious[nxt] = False
                    dfs2(nxt)

        for i in range(n):
            if not suspicious[i] and not visited[i]:
                dfs2(i)

        return [i for i in range(n) if not suspicious[i]]
