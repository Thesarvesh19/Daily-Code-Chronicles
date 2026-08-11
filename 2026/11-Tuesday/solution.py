class Solution:
    def missingInteger(self, nums: List[int]) -> int:
        total = nums[0]

        # Sum of the longest sequential prefix
        for i in range(1, len(nums)):
            if nums[i] == nums[i - 1] + 1:
                total += nums[i]
            else:
                break

        # Store all elements
        nums_set = set(nums)

        # Find smallest missing integer >= total
        while total in nums_set:
            total += 1

        return total
