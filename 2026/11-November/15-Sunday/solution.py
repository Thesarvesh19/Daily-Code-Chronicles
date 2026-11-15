class Solution:
    def numOfSubarrays(self, arr: list[int]) -> int:
        MOD = 10**9 + 7
        
        # cnt[0] counts even prefix sums, cnt[1] counts odd prefix sums
        # Initialize cnt[0] = 1 for the base case (prefix sum of 0)
        cnt = [1, 0]
        prefix_sum = 0
        ans = 0
        
        for x in arr:
            prefix_sum += x
            parity = prefix_sum % 2
            
            # Add the count of prefix sums with the opposite parity
            ans = (ans + cnt[1 - parity]) % MOD
            
            # Record the current prefix sum parity
            cnt[parity] += 1
            
        return ans
