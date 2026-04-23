# 2615. Sum of Distances

from collections import defaultdict

class Solution:
    def distance(self, nums):
        index_map = defaultdict(list)
        
        # Step 1: group indices by value 
        for i, num in enumerate(nums):
            index_map[num].append(i)
        
        res = [0] * len(nums)
        
        # Step 2: process each group
        for indices in index_map.values():
            n = len(indices)
            
            # prefix sum
            prefix = [0] * (n + 1)
            for i in range(n):
                prefix[i + 1] = prefix[i] + indices[i]
            
            for i in range(n):
                idx = indices[i]
                
                # left side
                left_count = i
                left_sum = prefix[i]
                left = idx * left_count - left_sum
                
                # right side
                right_count = n - i - 1
                right_sum = prefix[n] - prefix[i + 1]
                right = right_sum - idx * right_count
                
                res[idx] = left + right
        
        return res
