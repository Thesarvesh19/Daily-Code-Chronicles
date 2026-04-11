from collections import defaultdict

class Solution:
    def minimumDistance(self, nums):
        pos = defaultdict(list)
        
        for i, val in enumerate(nums):
            pos[val].append(i)
        
        ans = float('inf')
        
        for indices in pos.values():
            if len(indices) >= 3:
                for i in range(len(indices) - 2):
                    ans = min(ans, 2 * (indices[i+2] - indices[i]))
        
        return ans if ans != float('inf') else -1
