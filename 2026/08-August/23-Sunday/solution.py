class Solution:
    def sumGame(self, num: str) -> bool:
        n = len(num)
        half = n // 2

        left_sum = right_sum = 0
        left_q = right_q = 0

        for i in range(half):
            if num[i] == '?':
                left_q += 1
            else:
                left_sum += int(num[i])

        for i in range(half, n):
            if num[i] == '?':
                right_q += 1
            else:
                right_sum += int(num[i])

        # Odd number of '?' means Alice gets one extra move.
        if (left_q + right_q) % 2 == 1:
            return True

        # Bob wins only when the sums can be perfectly balanced.
        return left_sum - right_sum != 9 * (right_q - left_q) // 2
