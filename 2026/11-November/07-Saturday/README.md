# LeetCode 1882 - Process Tasks Using Servers

## Problem
**Difficulty:** Medium  
**Topics:** Array, Heap (Priority Queue), Greedy, Simulation  
**Language:** Python 3

## Approach: Greedy + Two Min-Heaps

We use two min-heaps to efficiently manage available and busy servers.

### 1. Available Servers
Store servers as `(weight, index)`.

- Select the server with the smallest weight.
- If weights are equal, select the server with the smallest index.

### 2. Busy Servers
Store servers as `(finish_time, weight, index)`.

- Track when each server finishes its current task.
- Release servers whose finish time is less than or equal to the current time.
- If no server is available, advance time to the earliest finishing server.

## Python Solution

```python
import heapq

class Solution:
    def assignTasks(self, servers: list[int], tasks: list[int]) -> list[int]:
        available = [(weight, i) for i, weight in enumerate(servers)]
        heapq.heapify(available)

        busy = []
        result = []

        for time, duration in enumerate(tasks):
            while busy and busy[0][0] <= time:
                finish, weight, index = heapq.heappop(busy)
                heapq.heappush(available, (weight, index))

            if not available:
                time = busy[0][0]

                while busy and busy[0][0] <= time:
                    finish, weight, index = heapq.heappop(busy)
                    heapq.heappush(available, (weight, index))

            weight, index = heapq.heappop(available)
            result.append(index)

            heapq.heappush(
                busy,
                (time + duration, weight, index)
            )

        return result
```

## Example

**Input:**
```python
servers = [3, 3, 2]
tasks = [1, 2, 3, 2, 1, 2]
```

**Output:**
```python
[2, 2, 0, 2, 1, 2]
```

## Complexity Analysis

Let:
- `n` = Number of servers
- `m` = Number of tasks

| Complexity | Value | Explanation |
|---|---|---|
| Time | O((n + m) log n) | Heap operations for assigning and releasing servers |
| Space | O(n) | Two heaps store the servers |

## Key Takeaways

- Two min-heaps simplify server scheduling.
- Greedy selection ensures the server with the lowest weight is chosen first.
- Server indices resolve ties between servers with equal weights.
- Advancing time to the earliest finishing server avoids unnecessary simulation.

**LeetCode Problem:** [1882. Process Tasks Using Servers](https://leetcode.com/problems/process-tasks-using-servers/)
