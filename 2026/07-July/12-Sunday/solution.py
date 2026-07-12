class Solution:
    def arrayRankTransform(self, arr: List[int]) -> List[int]:
        rank = {}

        for value in sorted(arr):
            if value not in rank:
                rank[value] = len(rank) + 1

        return [rank[x] for x in arr]
