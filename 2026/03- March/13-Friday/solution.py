import math
from typing import List

class Solution:
    def minNumberOfSeconds(self, mountainHeight: int, workerTimes: List[int]) -> int:
        
        def can_finish(time):
            total = 0
            
            for w in workerTimes:
                val = (2 * time) // w
                x = int((math.sqrt(1 + 4 * val) - 1) // 2)
                total += x
                
                if total >= mountainHeight:
                    return True
            
            return False
        
        left = 0
        right = min(workerTimes) * mountainHeight * (mountainHeight + 1) // 2
        
        while left < right:
            mid = (left + right) // 2
            
            if can_finish(mid):
                right = mid
            else:
                left = mid + 1
        
        return left
