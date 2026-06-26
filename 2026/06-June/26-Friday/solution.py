class BIT:
    def __init__(self, n):
        self.n = n
        self.bit = [0] * (n + 1)

    def update(self, idx, val):
        while idx <= self.n:
            self.bit[idx] += val
            idx += idx & -idx

    def query(self, idx):
        s = 0
        while idx > 0:
            s += self.bit[idx]
            idx -= idx & -idx
        return s


class Solution:
    def countMajoritySubarrays(self, nums, target):
        n = len(nums)
        bit = BIT(2 * n + 2)

        prefix = n + 1
        bit.update(prefix, 1)

        ans = 0

        for x in nums:
            prefix += 1 if x == target else -1
            ans += bit.query(prefix - 1)
            bit.update(prefix, 1)

        return ans
