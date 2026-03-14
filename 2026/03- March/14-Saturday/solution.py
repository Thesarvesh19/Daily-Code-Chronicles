class Solution:
    def getHappyString(self, n: int, k: int) -> str:
        result = []

        def backtrack(current: str):
            if len(result) >= k:
                return

            if len(current) == n: 
                result.append(current)
                return

            for ch in ['a', 'b', 'c']:
                if not current or current[-1] != ch:
                    backtrack(current + ch)

        backtrack("")

        if k <= len(result):
            return result[k - 1]
        return ""
