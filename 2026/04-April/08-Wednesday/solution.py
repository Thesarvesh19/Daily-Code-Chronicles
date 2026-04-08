class Solution:
    def xorAfterQueries(self, nums, queries):
        MOD = 10**9 + 7

        for l, r, k, v in queries:
            i = l
            while i <= r: 
                nums[i] = (nums[i] * v) % MOD
                i += k

        result = 0
        for num in nums:
            result ^= num

        return result
