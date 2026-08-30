class Solution:
    def minimumDeletions(self, nums: List[int]) -> int:
        n = len(nums)

        # Find indices of minimum and maximum
        min_idx = nums.index(min(nums))
        max_idx = nums.index(max(nums))

        # Make min_idx the smaller index
        if min_idx > max_idx:
            min_idx, max_idx = max_idx, min_idx

        # 1. Remove both from the front
        front = max_idx + 1

        # 2. Remove both from the back
        back = n - min_idx

        # 3. Remove one from front and one from back
        both = (min_idx + 1) + (n - max_idx)

        return min(front, back, both)
