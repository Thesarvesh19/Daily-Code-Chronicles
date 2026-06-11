from collections import deque

class Solution:
    def assignEdgeWeights(self, edges):
        MOD = 10**9 + 7

        n = len(edges) + 1
        g = [[] for _ in range(n + 1)]
 
        for u, v in edges:
            g[u].append(v)
            g[v].append(u)

        q = deque([1])
        vis = {1}

        depth = -1

        while q:
            depth += 1

            for _ in range(len(q)):
                u = q.popleft()

                for v in g[u]:
                    if v not in vis:
                        vis.add(v)
                        q.append(v)

        return pow(2, depth - 1, MOD)
