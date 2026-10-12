
class Solution:
    def maxSum(self, nums: List[int], k: int) -> int:
        MOD = 10**9 + 7
        cnt = [0] * 31

        for num in nums:
            for i in range(31):
                if (num >> i) & 1:
                    cnt[i] += 1

        ans = 0

        for _ in range(k):
            num = 0
            for i in range(31):
                if cnt[i] > 0:
                    num |= 1 << i
                    cnt[i] -= 1

            ans = (ans + num * num) % MOD

        return ans
