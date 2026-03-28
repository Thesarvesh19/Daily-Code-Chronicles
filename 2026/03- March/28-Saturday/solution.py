#update
from typing import List

class Solution:
    def findTheString(self, lcp: List[List[int]]) -> str:
        n = len(lcp)

        # Step 1: Validate diagonal
        for i in range(n):
            if lcp[i][i] != n - i:
                return ""

        # Step 2: DSU (Union-Find)
        parent = list(range(n))

        def find(x):
            if parent[x] != x:
                parent[x] = find(parent[x])
            return parent[x]

        def union(x, y):
            px, py = find(x), find(y)
            if px != py:
                parent[py] = px

        # Merge indices where lcp > 0
        for i in range(n):
            for j in range(n):
                if lcp[i][j] > 0:
                    union(i, j)

        # Step 3: Assign characters
        group_char = {}
        current_char = ord('a')
        res = [''] * n

        for i in range(n):
            root = find(i)
            if root not in group_char:
                if current_char > ord('z'):
                    return ""
                group_char[root] = chr(current_char)
                current_char += 1
            res[i] = group_char[root]

        word = "".join(res)

        # Step 4: Validate LCP
        dp = [[0] * (n + 1) for _ in range(n + 1)]

        for i in range(n - 1, -1, -1):
            for j in range(n - 1, -1, -1):
                if word[i] == word[j]:
                    dp[i][j] = dp[i + 1][j + 1] + 1

        for i in range(n):
            for j in range(n):
                if dp[i][j] != lcp[i][j]:
                    return ""

        return word
