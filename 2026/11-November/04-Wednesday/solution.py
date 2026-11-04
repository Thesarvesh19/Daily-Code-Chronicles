import heapq
from collections import defaultdict

class Solution:
    def minOperations(self, nums: list[int], x: int, k: int) -> int:
        n = len(nums)

        small = []
        large = []
        delayed = defaultdict(int)

        small_sum = 0
        large_sum = 0
        small_size = 0
        large_size = 0

        def prune(heap, is_small):
            while heap:
                val = -heap[0] if is_small else heap[0]
                if delayed[val] == 0:
                    break
                delayed[val] -= 1
                heapq.heappop(heap)

        def rebalance():
            nonlocal small_size, large_size
            nonlocal small_sum, large_sum

            while small_size > large_size + 1:
                prune(small, True)
                val = -heapq.heappop(small)
                heapq.heappush(large, val)

                small_size -= 1
                large_size += 1
                small_sum -= val
                large_sum += val

            while small_size < large_size:
                prune(large, False)
                val = heapq.heappop(large)
                heapq.heappush(small, -val)

                large_size -= 1
                small_size += 1
                large_sum -= val
                small_sum += val

        def add(val):
            nonlocal small_size, large_size
            nonlocal small_sum, large_sum

            prune(small, True)

            if not small or val <= -small[0]:
                heapq.heappush(small, -val)
                small_size += 1
                small_sum += val
            else:
                heapq.heappush(large, val)
                large_size += 1
                large_sum += val

            rebalance()

        def remove(val):
            nonlocal small_size, large_size
            nonlocal small_sum, large_sum

            prune(small, True)
            prune(large, False)

            delayed[val] += 1

            if val <= -small[0]:
                small_size -= 1
                small_sum -= val

                if val == -small[0]:
                    prune(small, True)
            else:
                large_size -= 1
                large_sum -= val

                if large and val == large[0]:
                    prune(large, False)

            rebalance()

        def get_cost():
            prune(small, True)
            median = -small[0]

            return (
                median * small_size - small_sum
                + large_sum - median * large_size
            )

        # Calculate minimum cost for every window of size x.
        costs = []

        for i in range(n):
            add(nums[i])

            if i >= x:
                remove(nums[i - x])

            if i >= x - 1:
                costs.append(get_cost())

        # Dynamic Programming.
        m = len(costs)
        inf = float('inf')

        prev = [0] * (n + 1)

        for j in range(1, k + 1):
            curr = [inf] * (n + 1)

            for i in range(1, n + 1):
                curr[i] = curr[i - 1]

                if i >= x:
                    curr[i] = min(
                        curr[i],
                        prev[i - x] + costs[i - x]
                    )

            prev = curr

        return prev[n]
