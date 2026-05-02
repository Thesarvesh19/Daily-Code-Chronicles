class Solution:
    def rotatedDigits(self, n: int) -> int:
        def is_good(num):
            changed = False
            
            while num > 0:
                digit = num % 10
                
                if digit in [3, 4, 7]:
                    return False
                
                if digit in [2, 5, 6, 9]:
                    changed = True
                
                num //= 10
            
            return changed
        
        count = 0
        for i in range(1, n + 1):
            if is_good(i):
                count += 1
        
        return count
