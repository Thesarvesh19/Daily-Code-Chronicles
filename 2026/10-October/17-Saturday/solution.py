
class Solution:
    def minSwaps(self, nums: List[int]) -> int:
        def digit_sum(x):
            return sum(int(d) for d in str(x))

        sorted_nums = sorted(nums, key=lambda x: (digit_sum(x), x))
        position = {num: i for i, num in enumerate(sorted_nums)}

        n = len(nums)
        visited = [False] * n
        swaps = 0

        for i in range(n):
            if visited[i]:
                continue

            j = i
            cycle_size = 0

            while not visited[j]:
                visited[j] = True
                j = position[nums[j]]
                cycle_size += 1

            if cycle_size > 1:
                swaps += cycle_size - 1

        return swaps
