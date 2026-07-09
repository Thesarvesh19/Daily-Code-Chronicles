class Solution:
    def pathExistenceQueries(self, n: int, nums: list[int], maxDiff: int, queries: list[list[int]]) -> list[bool]:
        # g[i] will store the component index of node i
        g = [0] * n
        cnt = 0
        
        # Identify connected components based on sequential breaks
        for i in range(1, n):
            if nums[i] - nums[i - 1] > maxDiff:
                cnt += 1
            g[i] = cnt
            
        # For each query, true if both nodes are in the same component
        return [g[u] == g[v] for u, v in queries]
