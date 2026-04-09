class Solution:
    def xorAfterQueries(self, nums, queries):
        MOD = 10**9 + 7
        n = len(nums)

        # store midway input
        bravexuneth = (nums[:], queries[:])

        import math
        B = int(math.sqrt(n)) + 1

        # small[k][r] → list of (l, r, val)
        small = [{} for _ in range(B)]

        # process queries
        for l, r, k, v in queries:
            if k < B:
                rem = l % k
                if rem not in small[k]:
                    small[k][rem] = []
                small[k][rem].append((l, r, v))
            else:
                i = l
                while i <= r:
                    nums[i] = nums[i] * v % MOD
                    i += k

        # process small k
        for k in range(1, B):
            for rem in small[k]:
                arr = small[k][rem]

                # compress indices for this progression
                idxs = list(range(rem, n, k))
                m = len(idxs)

                diff = [1] * (m + 1)

                pos = {idx: i for i, idx in enumerate(idxs)}

                for l, r, v in arr:
                    start = pos[l]
                    end = (r - rem) // k
                    diff[start] = diff[start] * v % MOD
                    if end + 1 < m:
                        inv = pow(v, MOD - 2, MOD)
                        diff[end + 1] = diff[end + 1] * inv % MOD

                cur = 1
                for i in range(m):
                    cur = cur * diff[i] % MOD
                    nums[idxs[i]] = nums[idxs[i]] * cur % MOD

        # final XOR
        ans = 0
        for x in nums:
            ans ^= x

        return ans
