"""
Problem: Reverse Bits

Reverse bits of a given 32-bit unsigned integer. 

Approach:
Iterate through all 32 bits:
    - Shift result left
    - Add last bit of n using (n & 1)
    - Shift n right

Time Complexity: O(1)  (32 iterations)
Space Complexity: O(1)
"""

class Solution:
    def reverseBits(self, n):
        result = 0

        for _ in range(32):
            result <<= 1
            result |= (n & 1)
            n >>= 1

        return result
