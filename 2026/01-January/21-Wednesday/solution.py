class Solution:
    def minBitwiseArray(self, nums):
        ans = []

        for n in nums:
            if n % 2 == 0:
                ans.append(-1)
            else:
                count = 0
                temp = n
                while temp & 1:
                    count += 1
                    temp >>= 1

                ans.append(n - (1 << (count - 1)))

        return ans
