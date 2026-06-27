from collections import Counter

class Solution:
    def maximumLength(self, nums: list[int]) -> int:
        count = Counter(nums)
        
        # Handle edge case for 1: max odd number of 1s
        ans = count[1] - (count[1] % 2 == 0) if count[1] > 0 else 1
        
        for num in count:
            if num == 1:
                continue
                
            length = 0
            x = num
            
            # As long as we have at least 2 of the current number, we can extend both sides
            while count[x] >= 2:
                length += 2
                x *= x
            
            # Check if the next squared element can serve as the single peak element
            if count[x] >= 1:
                length += 1
            else:
                # If it doesn't exist, the last element we counted twice must act as the peak
                length -= 1
                
            ans = max(ans, length)
            
        return ans
