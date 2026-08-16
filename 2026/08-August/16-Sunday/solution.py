class Solution:
    def stoneGameIX(self, stones: list[int]) -> bool:
        count = [0, 0, 0]

        for x in stones:
            count[x % 3] += 1

        # If number of remainder-0 stones is even,
        # Alice needs at least one stone of both types 1 and 2.
        if count[0] % 2 == 0:
            return min(count[1], count[2]) > 0

        # If number of remainder-0 stones is odd,
        # the difference between counts of 1 and 2 must be > 2.
        return abs(count[1] - count[2]) > 2
