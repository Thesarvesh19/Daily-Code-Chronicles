from typing import List

class Solution:
    def findKthSmallest(self, coins: List[int], k: int) -> int:
        from math import gcd

        def lcm(a, b):
            return a // gcd(a, b) * b

        def count(x):
            # Count numbers <= x divisible by at least one coin
            n = len(coins)
            total = 0

            # Inclusion-exclusion
            for mask in range(1, 1 << n):
                multiple = 1
                bits = 0
                valid = True

                for i in range(n):
                    if mask & (1 << i):
                        bits += 1
                        multiple = lcm(multiple, coins[i])

                        if multiple > x:
                            valid = False
                            break

                if not valid:
                    continue

                cnt = x // multiple

                if bits % 2 == 1:
                    total += cnt
                else:
                    total -= cnt

            return total

        left = 1
        right = min(coins) * k

        while left < right:
            mid = (left + right) // 2

            if count(mid) >= k:
                right = mid
            else:
                left = mid + 1

        return left
