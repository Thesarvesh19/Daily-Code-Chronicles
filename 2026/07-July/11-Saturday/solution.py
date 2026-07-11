from typing import List

class Solution:
    def countCompleteComponents(self, n: int, edges: List[List[int]]) -> int:
        graph = [[] for _ in range(n)]
        for u, v in edges:
            graph[u].append(v)
            graph[v].append(u)

        visited = [False] * n
        answer = 0

        for start in range(n):
            if visited[start]:
                continue

            stack = [start]
            visited[start] = True
            nodes = 0
            degree_sum = 0

            while stack:
                node = stack.pop()
                nodes += 1
                degree_sum += len(graph[node])

                for nxt in graph[node]:
                    if not visited[nxt]:
                        visited[nxt] = True
                        stack.append(nxt)

            if degree_sum // 2 == nodes * (nodes - 1) // 2:
                answer += 1

        return answer
