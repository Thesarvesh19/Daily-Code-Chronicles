class Solution:
    def sortByBits(self, arr):
        # Sort by number of 1 bits, then by numeric value
        return sorted(arr, key=lambda x: (bin(x).count('1'), x))
