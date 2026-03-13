# 3296. Minimum Number of Seconds to Make Mountain Height Zero

## Problem

You are given an integer `mountainHeight` representing the height of a mountain.

You are also given an integer array `workerTimes` where `workerTimes[i]` represents the base work time of worker `i`.

Workers operate **simultaneously** to reduce the mountain height.

For worker `i`, reducing the mountain height by `x` takes:

workerTimes[i] * 1 + workerTimes[i] * 2 + ... + workerTimes[i] * x seconds

This is equivalent to:

workerTimes[i] * (x * (x + 1) / 2)

Return the **minimum number of seconds** required to reduce the mountain height to **0**.

---

## Example 1

Input

mountainHeight = 4  
workerTimes = [2,1,1]

Output

3

Explanation

Worker 0 reduces height by 1 → 2 seconds  
Worker 1 reduces height by 2 → 3 seconds  
Worker 2 reduces height by 1 → 1 second  

Since workers work simultaneously, total time = **max(2,3,1) = 3**

---

## Example 2

Input

mountainHeight = 10  
workerTimes = [3,2,2,4]

Output

12

---

## Example 3

Input

mountainHeight = 5  
workerTimes = [1]

Output

15

---

# Approach

The time required for a worker to reduce `x` height is:

T = workerTime × (x(x+1) / 2)

Instead of assigning work directly, we **binary search the minimum time** needed.

For a given time `T`, we compute how much height each worker can reduce.

From:

workerTime × (x(x+1)/2) ≤ T

we derive:

x(x+1) ≤ 2T / workerTime

Solving this quadratic inequality gives:

x = floor((sqrt(1 + 8T / workerTime) − 1) / 2)

We sum the contributions of all workers and check if the total height reduced is at least `mountainHeight`.

---

# Algorithm

1. Binary search on time.
2. For a given time `T`, compute maximum height each worker can reduce.
3. Sum the heights reduced by all workers.
4. If total ≥ mountainHeight → time is valid.
5. Otherwise increase time.

---

# Complexity Analysis

Time Complexity

O(n log T)

where

- n = number of workers
- T = maximum possible time

Space Complexity

O(1)

---

# Python Implementation

```python
import math
from typing import List

class Solution:
    def minNumberOfSeconds(self, mountainHeight: int, workerTimes: List[int]) -> int:

        def can_finish(time):
            total = 0
            for w in workerTimes:
                val = (2 * time) // w
                x = int((math.sqrt(1 + 4 * val) - 1) // 2)
                total += x
                if total >= mountainHeight:
                    return True
            return False

        left = 0
        right = min(workerTimes) * mountainHeight * (mountainHeight + 1) // 2

        while left < right:
            mid = (left + right) // 2
            if can_finish(mid):
                right = mid
            else:
                left = mid + 1

        return left
