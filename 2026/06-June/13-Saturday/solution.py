class Solution:
    def mapWordWeights(self, words: List[str], weights: List[int]) -> str:
        ans = []

        for word in words:
            total = sum(weights[ord(ch) - ord('a')] for ch in word)
            total %= 26
            ans.append(chr(ord('a') + (25 - total)))

        return "".join(ans)
