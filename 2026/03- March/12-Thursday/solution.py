from typing import List


class Solution:
    def maxStability(self, n: int, edges: List[List[int]], k: int) -> int:
        parent = list(range(n))
        rank = [0] * n

        def find(x):
            while parent[x] != x:
                parent[x] = parent[parent[x]]
                x = parent[x]
            return x

        def union(a, b):
            ra, rb = find(a), find(b)
            if ra == rb:
                return False
            if rank[ra] < rank[rb]:
                parent[ra] = rb
            elif rank[ra] > rank[rb]:
                parent[rb] = ra
            else:
                parent[rb] = ra
                rank[ra] += 1
            return True

        dsu_parent = list(range(n))
        dsu_rank = [0] * n

        def find0(x):
            while dsu_parent[x] != x:
                dsu_parent[x] = dsu_parent[dsu_parent[x]]
                x = dsu_parent[x]
            return x

        def union0(a, b):
            ra, rb = find0(a), find0(b)
            if ra == rb:
                return False
            if dsu_rank[ra] < dsu_rank[rb]:
                dsu_parent[ra] = rb
            elif dsu_rank[ra] > dsu_rank[rb]:
                dsu_parent[rb] = ra
            else:
                dsu_parent[rb] = ra
                dsu_rank[ra] += 1
            return True

        mandatory_count = 0
        for u, v, s, m in edges:
            if m == 1:
                if not union0(u, v):
                    return -1
                mandatory_count += 1

        if mandatory_count > n - 1:
            return -1

        def can(x):
            parent = list(range(n))
            rank = [0] * n

            def find(x):
                while parent[x] != x:
                    parent[x] = parent[parent[x]]
                    x = parent[x]
                return x

            def union(a, b):
                ra, rb = find(a), find(b)
                if ra == rb:
                    return False
                if rank[ra] < rank[rb]:
                    parent[ra] = rb
                elif rank[ra] > rank[rb]:
                    parent[rb] = ra
                else:
                    parent[rb] = ra
                    rank[ra] += 1
                return True

            upgrades = 0
            edges_used = 0

            for u, v, s, m in edges:
                if m == 1:
                    if s < x:
                        return False
                    if union(u, v):
                        edges_used += 1

            optional = []

            for u, v, s, m in edges:
                if m == 0:
                    if s >= x:
                        optional.append((0, u, v))
                    elif s * 2 >= x:
                        optional.append((1, u, v))

            optional.sort()

            for cost, u, v in optional:
                if union(u, v):
                    edges_used += 1
                    upgrades += cost

                    if upgrades > k:
                        return False

                    if edges_used == n - 1:
                        return True

            return edges_used == n - 1 and upgrades <= k

        lo, hi = 0, 2 * 10**5
        ans = -1

        while lo <= hi:
            mid = (lo + hi) // 2

            if can(mid):
                ans = mid
                lo = mid + 1
            else:
                hi = mid - 1

        return ans
