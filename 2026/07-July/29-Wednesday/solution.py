from collections import Counter

class Solution:
    def __init__(self):
        self.MAX = 10**6 + 1

    def smallestPalindrome(self, s: str, k: int) -> str:
        count = Counter(s)

        halfCount = [0] * 26
        midLetter = ""

        for c, freq in count.items():
            halfCount[ord(c) - ord("a")] = freq // 2
            if freq % 2:
                midLetter = c

        if self._countArrangements(halfCount) < k:
            return ""

        left = []
        halfLen = sum(halfCount)

        for _ in range(halfLen):
            for i in range(26):
                if halfCount[i] == 0:
                    continue

                halfCount[i] -= 1
                ways = self._countArrangements(halfCount)

                if ways >= k:
                    left.append(chr(i + ord("a")))
                    break

                k -= ways
                halfCount[i] += 1

        return "".join(left) + midLetter + "".join(reversed(left))

    def _countArrangements(self, cnt):
        total = sum(cnt)
        res = 1

        for f in cnt:
            res *= self._nCk(total, f)
            if res >= self.MAX:
                return self.MAX
            total -= f

        return res

    def _nCk(self, n, k):
        k = min(k, n - k)
        res = 1

        for i in range(1, k + 1):
            res = res * (n - i + 1) // i
            if res >= self.MAX:
                return self.MAX

        return res
