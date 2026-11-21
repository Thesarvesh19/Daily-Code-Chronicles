class Solution:
    def findSubtreeSizes(self, parent: List[int], s: str) -> List[int]:
        n = len(parent)
        adj = [[] for _ in range(n)]

        for i in range(1, n):
            adj[parent[i]].append(i)

        new_parent = parent[:]

        def dfs(u, ancestors):
            ancestors.append(u)

            for v in adj[u]:
                x = v
                for a in reversed(ancestors[:-1]):
                    if s[a] == s[v]:
                        new_parent[v] = a
                        break
                dfs(v, ancestors)

            ancestors.pop()

        dfs(0, [])

        new_adj = [[] for _ in range(n)]
        for i in range(1, n):
            new_adj[new_parent[i]].append(i)

        ans = [0] * n

        def calc(u):
            ans[u] = 1
            for v in new_adj[u]:
                ans[u] += calc(v)
            return ans[u]

        calc(0)
        return ans
