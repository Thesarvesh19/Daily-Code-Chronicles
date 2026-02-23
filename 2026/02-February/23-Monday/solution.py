class Solution:
    def hasAllCodes(self, s, k):
        total = 1 << k  # 2^k
        
        # Early check
        if len(s) - k + 1 < total:
            return False
        
        seen = set()
        
        for i in range(len(s) - k + 1):
            seen.add(s[i:i+k])
            if len(seen) == total:
                return True
        
        return False
