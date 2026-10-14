
class Solution:
    def maxSumOfSquares(self, num: int, sum: int) -> str:
        if sum > 9 * num:
            return ""

        k, rem = divmod(sum, 9)

        ans = "9" * k

        if rem:
            ans += str(rem)

        ans += "0" * (num - len(ans))

        return ans
