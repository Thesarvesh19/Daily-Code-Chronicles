class Solution:
    def countMajoritySubarrays(self, nums: list[int], target: int) -> int:
        n = len(nums)
        ans = 0
        
        for i in range(n):
            cnt = 0
            for j in range(i, n):
                # +1 if it matches target, 0 otherwise
                cnt += 1 if nums[j] == target else 0
                length = j - i + 1
                
                # Check if it appears strictly more than half the time
                if cnt * 2 > length:
                    ans += 1
                    
        return ans
