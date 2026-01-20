class Solution:
    def minBitwiseArray(self, nums):
        ans = []
        
        
        for p in nums:
            res = -1
            
            
            for x in range(p):
                if (x | (x + 1)) == p:
                    res = x
                    break
            
           
            ans.append(res)
            
        return ans
