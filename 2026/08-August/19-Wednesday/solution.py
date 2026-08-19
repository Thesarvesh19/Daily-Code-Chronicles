class Solution:
    def maxNumberOfFamilies(self, n: int, reservedSeats: list[list[int]]) -> int:
        reserved = {}

        for r, c in reservedSeats:
            reserved.setdefault(r, set()).add(c)

        # Four possible groups of 4 seats:
        # Left:   2,3,4,5
        # Middle: 4,5,6,7
        # Right:  6,7,8,9

        ans = (n - len(reserved)) * 2

        for seats in reserved.values():
            left = all(c not in seats for c in [2, 3, 4, 5])
            middle = all(c not in seats for c in [4, 5, 6, 7])
            right = all(c not in seats for c in [6, 7, 8, 9])

            if left and right:
                ans += 2
            elif left or middle or right:
                ans += 1

        return ans
