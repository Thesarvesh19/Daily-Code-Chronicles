class Solution:
    def minSumOfLengths(self, arr: list[int], target: int) -> int:
        n = len(arr)
        INF = 10**9

        # prefix_sum -> latest index
        prefix = {0: 0}

        # best[i] = minimum length of a valid subarray
        # completely inside the first i elements
        best = [INF] * (n + 1)

        total = 0
        ans = INF

        for i in range(1, n + 1):
            total += arr[i - 1]

            # Carry forward the previous best
            best[i] = best[i - 1]

            # Look for a previous prefix sum
            if total - target in prefix:
                j = prefix[total - target]
                length = i - j

                # best[j] ends before this subarray starts
                if best[j] != INF:
                    ans = min(ans, best[j] + length)

                best[i] = min(best[i], length)

            # Store latest occurrence
            prefix[total] = i

        return -1 if ans == INF else ans
