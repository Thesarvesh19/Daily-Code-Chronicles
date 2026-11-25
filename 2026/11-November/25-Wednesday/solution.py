class Solution:
    def smallestUniqueSubarray(self, nums: List[int]) -> int:
        n = len(nums)
        base = 233
        mod1 = 1000000007
        mod2 = 998244353

        def check(length):
            freq = {}

            h1 = h2 = 0
            p1 = p2 = 1

            for i in range(n):
                h1 = (h1 * base + nums[i]) % mod1
                h2 = (h2 * base + nums[i]) % mod2

                if i >= length:
                    h1 = (h1 - nums[i - length] * p1) % mod1
                    h2 = (h2 - nums[i - length] * p2) % mod2
                else:
                    p1 = (p1 * base) % mod1
                    p2 = (p2 * base) % mod2

                if i >= length - 1:
                    key = (h1, h2)
                    freq[key] = freq.get(key, 0) + 1

            return any(v == 1 for v in freq.values())

        left, right = 1, n

        while left < right:
            mid = (left + right) // 2

            if check(mid):
                right = mid
            else:
                left = mid + 1

        return left
