class Solution:
    def findThePrefixCommonArray(self, A, B):
        n = len(A)
        count = [0]*(n+1)
        ans = []
        common = 0

        for a, b in zip(A, B):
            count[a] += 1
            if count[a] == 2:
                common += 1

            count[b] += 1
            if count[b] == 2:
                common += 1

            ans.append(common)

        return ans
