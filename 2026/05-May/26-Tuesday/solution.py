class Solution:
    def numberOfSpecialChars(self, word: str) -> int:
        lower = {}
        upper = {}

        for i, ch in enumerate(word):

            if ch.islower():
                lower[ch] = i

            else:
                if ch not in upper:
                    upper[ch] = i

        ans = 0

        for ch in lower:
            up = ch.upper()

            if up in upper and lower[ch] < upper[up]:
                ans += 1

        return ans
