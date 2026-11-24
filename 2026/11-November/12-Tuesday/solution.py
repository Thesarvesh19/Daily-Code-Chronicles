class Solution:
    def maxLength(self, nums: List[int]) -> int:
        n = len(nums)
        ans = 0

        for i in range(n):
            for j in range(i, n):
                prod = 1
                lcm = 1
                gcd_val = 1

                for k in range(i, j + 1):
                    prod *= nums[k]
                    gcd_val = math.gcd(gcd_val, nums[k])
                    lcm = math.lcm(lcm, nums[k])

                if prod == lcm * gcd_val:
                    ans = max(ans, j - i + 1)

        return ans
