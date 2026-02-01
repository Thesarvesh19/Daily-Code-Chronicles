class Solution:
    """
    You are given an array of integers nums of length n.

    The cost of an array is the value of its first element.
    For example:
    - cost of [1, 2, 3] is 1
    - cost of [3, 4, 1] is 3

    You need to divide nums into 3 disjoint contiguous subarrays.

    Return the minimum possible sum of the cost of these subarrays.

    Constraints:
    - 3 <= n <= 50
    - 1 <= nums[i] <= 50
    """

    def minimumCost(self, nums):
        n = len(nums)
        ans = float('inf')

        for i in range(1, n - 1):
            for j in range(i + 1, n):
                ans = min(ans, nums[0] + nums[i] + nums[j])

        return ans
