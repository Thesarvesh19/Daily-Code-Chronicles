from typing import List

class Solution:
    def resultArray(self, nums: List[int], k: int) -> List[int]:
        # ans[r] = total number of subarrays
        # whose product % k == r
        ans = [0] * k

        # dp[r] = number of subarrays ending at the
        # previous position with product % k == r
        dp = [0] * k

        for num in nums:
            num_mod = num % k

            # Subarrays ending at the current position
            new_dp = [0] * k

            # Start a new subarray containing only num
            new_dp[num_mod] += 1

            # Extend every previous subarray
            for r in range(k):
                new_r = (r * num_mod) % k
                new_dp[new_r] += dp[r]

            # Add current subarrays to the final answer
            for r in range(k):
                ans[r] += new_dp[r]

            dp = new_dp

        return ans
