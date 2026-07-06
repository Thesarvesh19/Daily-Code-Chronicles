class Solution:
    def removeCoveredIntervals(self, intervals):
        intervals.sort(key=lambda x: (x[0], -x[1]))

        visible = 0
        furthest = -1

        for left, right in intervals:
            if right > furthest:
                visible += 1
                furthest = right

        return visible
