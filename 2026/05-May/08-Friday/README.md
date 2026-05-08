# LeetCode 3629 - Minimum Jumps to Reach End via Prime Teleportation

## Problem Statement
You are given an integer array `nums`.

From index `i`, you can move to:
- `i - 1`
- `i + 1`
- Any index `j` where `nums[i]` is prime and divides `nums[j]`

Return the minimum number of jumps required to reach the last index.

---

## Approach
 
We use:

- **BFS (Breadth First Search)** for shortest path
- **Sieve of Smallest Prime Factor (SPF)** for fast prime factorization
- Hash map to store indices sharing the same prime factor

### Steps
1. Precompute smallest prime factors.
2. Store all indices for every prime factor.
3. Start BFS from index `0`.
4. Move left, right, or teleport using prime values.
5. Return minimum jumps when reaching last index.

---

## Time Complexity

- Sieve: `O(max(nums) log log max(nums))`
- BFS: `O(n)`

Overall: **Efficient for large constraints**

---

## Python Solution

```python
from collections import deque, defaultdict
from typing import List

class Solution:
    def smallestPrimeFactor(self, limit):
        spf = list(range(limit + 1))

        for i in range(2, int(limit ** 0.5) + 1):
            if spf[i] == i:
                for j in range(i * i, limit + 1, i):
                    if spf[j] == j:
                        spf[j] = i

        return spf

    def minJumps(self, nums: List[int]) -> int:
        n = len(nums)

        if n == 1:
            return 0

        mx = max(nums)
        spf = self.smallestPrimeFactor(mx)

        bucket = defaultdict(list)

        for i, x in enumerate(nums):
            temp = x

            while temp > 1:
                p = spf[temp]
                bucket[p].append(i)

                while temp % p == 0:
                    temp //= p

        dist = [-1] * n
        dist[0] = 0

        q = deque([0])
        usedPrime = set()

        while q:
            i = q.popleft()

            if i == n - 1:
                return dist[i]

            if i - 1 >= 0 and dist[i - 1] == -1:
                dist[i - 1] = dist[i] + 1
                q.append(i - 1)

            if i + 1 < n and dist[i + 1] == -1:
                dist[i + 1] = dist[i] + 1
                q.append(i + 1)

            val = nums[i]

            if val > 1 and spf[val] == val and val not in usedPrime:
                usedPrime.add(val)

                for nxt in bucket[val]:
                    if dist[nxt] == -1:
                        dist[nxt] = dist[i] + 1
                        q.append(nxt)

        return -1
