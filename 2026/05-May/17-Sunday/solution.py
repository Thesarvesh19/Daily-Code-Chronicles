class Solution:
    def canReach(self, arr, start):

        if start < 0 or start >= len(arr) or arr[start] < 0:
            return False

        if arr[start] == 0:
            return True

        jump = arr[start]
        arr[start] *= -1

        return (self.canReach(arr, start + jump) or
                self.canReach(arr, start - jump))
