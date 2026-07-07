class Solution:
    def sumAndMultiply(self, n: int) -> int:
        digits = []

        while n > 0:
            d = n % 10
            if d:
                digits.append(d)
            n //= 10

        digits.reverse()

        value = 0
        digit_sum = 0

        for d in digits:
            value = value * 10 + d
            digit_sum += d

        return value * digit_sum
