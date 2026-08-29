class Solution:
    def lexicographicallySmallestArray(self, nums: List[int], limit: int) -> List[int]:
        n = len(nums)

        # Store (value, original_index) and sort by value
        arr = sorted((value, i) for i, value in enumerate(nums))

        ans = [0] * n
        i = 0

        while i < n:
            j = i

            # Find a group where consecutive values differ by <= limit
            while j + 1 < n and arr[j + 1][0] - arr[j][0] <= limit:
                j += 1

            # Values in this group can be freely rearranged.
            # Put the smallest values into the smallest indices.
            values = [arr[k][0] for k in range(i, j + 1)]
            indices = sorted(arr[k][1] for k in range(i, j + 1))

            for idx, value in zip(indices, values):
                ans[idx] = value

            i = j + 1

        return ans
