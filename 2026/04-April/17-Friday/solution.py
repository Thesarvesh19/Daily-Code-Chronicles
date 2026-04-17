# Minimum Absolute Distance Between Mirror Pairs

class Solution:
    def minMirrorPairDistance(self, nums):
        def reverse(x):
            rev = 0
            while x:
                rev = rev * 10 + x % 10
                x //= 10
            return rev 
        
        last_seen = {}
        ans = float('inf')
        
        for j, num in enumerate(nums):
            if num in last_seen:
                ans = min(ans, j - last_seen[num])
            
            rev = reverse(num)
            last_seen[rev] = j
        
        return ans if ans != float('inf') else -1
