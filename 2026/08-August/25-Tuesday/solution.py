class Solution:
    def missingMultiple(self, nums: List[int], k: int) -> int:
        st = set(nums)

        x = k
        while x in st:
            x += k

        return x
