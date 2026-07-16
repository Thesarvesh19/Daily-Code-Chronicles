from math import gcd
from typing import List

class Solution:
    def gcdSum(self, nums: List[int]) -> int:
        prefix = []
        current_max = 0

        for value in nums:
            if value > current_max:
                current_max = value
            prefix.append(gcd(value, current_max))

        prefix.sort()

        answer = 0
        left = 0
        right = len(prefix) - 1

        while left < right:
            answer += gcd(prefix[left], prefix[right])
            left += 1
            right -= 1

        return answer
