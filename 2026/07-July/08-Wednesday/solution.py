class Solution:
    def concatNonZero(self, s: str, queries: List[List[int]]) -> List[int]:
        MOD = 1_000_000_007
        n = len(s)

        digits = []
        positions = []

        for i, ch in enumerate(s):
            if ch != '0':
                digits.append(ord(ch) - ord('0'))
                positions.append(i)

        m = len(digits)

        if m == 0:
            return [0] * len(queries)

        power10 = [1] * (m + 1)
        for i in range(1, m + 1):
            power10[i] = (power10[i - 1] * 10) % MOD

        prefix_num = [0] * (m + 1)
        prefix_sum = [0] * (m + 1)

        for i in range(m):
            prefix_num[i + 1] = (prefix_num[i] * 10 + digits[i]) % MOD
            prefix_sum[i + 1] = prefix_sum[i] + digits[i]

        first_non_zero = [m] * (n + 1)
        idx = m - 1
        for i in range(n - 1, -1, -1):
            if idx >= 0 and positions[idx] == i:
                first_non_zero[i] = idx
                idx -= 1
            else:
                first_non_zero[i] = first_non_zero[i + 1]

        last_non_zero = [-1] * n
        idx = 0
        current = -1
        for i in range(n):
            if idx < m and positions[idx] == i:
                current = idx
                idx += 1
            last_non_zero[i] = current

        answer = []

        for left, right in queries:
            l = first_non_zero[left]
            r = last_non_zero[right]

            if l > r or l == m or r == -1:
                answer.append(0)
                continue

            length = r - l + 1

            value = (
                prefix_num[r + 1]
                - prefix_num[l] * power10[length]
            ) % MOD

            digit_sum = prefix_sum[r + 1] - prefix_sum[l]

            answer.append((value * digit_sum) % MOD)

        return answer
