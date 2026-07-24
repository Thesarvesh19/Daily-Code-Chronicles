from typing import List

class Solution:
    def uniqueXorTriplets(self, nums: List[int]) -> int:
        n = len(nums)
        if n == 1:
            return 1

        pair_xors = set()

        for i in range(n):
            x = nums[i]
            for j in range(i + 1, n):
                pair_xors.add(x ^ nums[j])

        triplet_xors = set()

        for px in pair_xors:
            for v in nums:
                triplet_xors.add(px ^ v)

        return len(triplet_xors)
