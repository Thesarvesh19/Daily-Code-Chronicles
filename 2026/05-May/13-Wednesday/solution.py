class Solution:
    def minMoves(self, nums: List[int], limit: int) -> int:
        n = len(nums)
        diff = [0] * (2 * limit + 2)
 
        for i in range(n // 2):
            a = nums[i]
            b = nums[n - 1 - i]

            low = min(a, b)
            high = max(a, b)
            total = a + b

            diff[2] += 2
            diff[low + 1] -= 1
            diff[total] -= 1
            diff[total + 1] += 1
            diff[high + limit + 1] += 1

        ans = float('inf')
        curr = 0

        for s in range(2, 2 * limit + 1):
            curr += diff[s]
            ans = min(ans, curr)

        return ans
