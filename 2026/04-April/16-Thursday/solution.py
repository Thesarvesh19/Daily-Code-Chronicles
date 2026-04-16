from collections import defaultdict
import bisect

class Solution:
    def solveQueries(self, nums, queries):
        n = len(nums)
        pos = defaultdict(list)
        
        for i, num in enumerate(nums):
            pos[num].append(i)
        
        res = []
        
        for q in queries:
            indices = pos[nums[q]]
            
            if len(indices) == 1:
                res.append(-1)
                continue
            
            i = bisect.bisect_left(indices, q)
            
            left = indices[i - 1] if i > 0 else indices[-1]
            right = indices[i + 1] if i < len(indices) - 1 else indices[0]
            
            d1 = abs(q - left)
            d2 = abs(q - right)
            
            d1 = min(d1, n - d1)
            d2 = min(d2, n - d2)
            
            res.append(min(d1, d2))
        
        return res
