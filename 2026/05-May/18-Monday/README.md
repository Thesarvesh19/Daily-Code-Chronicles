# 1345. Jump Game IV

## Problem Statement
You are given an integer array `arr`.

From index `i`, you can jump to:

- `i + 1` (if valid)
- `i - 1` (if valid)
- Any index `j` where:

```text
arr[i] == arr[j]
and i != j
```

Return the **minimum number of steps** needed to reach the last index starting from index `0`.

---

## Example

### Input
```text
arr = [100,-23,-23,404,100,23,23,23,3,404]
```

### Output
```text
3
```

### Explanation
Possible path:

```text
Index: 0 → 4 → 3 → 9
Steps: 3
```

---

# Approach (BFS + HashMap)

Since every jump costs **1 move**, we use **Breadth First Search (BFS)** to find the shortest path.

We store all indices having the same value using a hashmap.

For each position, explore:

1. Previous index `(i-1)`
2. Next index `(i+1)`
3. All indices with same value

To avoid repeated processing, clear visited value groups.

---

## Python Solution

```python
from collections import defaultdict, deque

class Solution:
    def minJumps(self, arr):
        n = len(arr)

        if n == 1:
            return 0

        mp = defaultdict(list)

        for i, val in enumerate(arr):
            mp[val].append(i)

        q = deque([0])
        visited = {0}
        steps = 0

        while q:

            for _ in range(len(q)):
                curr = q.popleft()

                if curr == n - 1:
                    return steps

                neighbors = mp[arr[curr]] + [curr-1, curr+1]

                for nxt in neighbors:

                    if 0 <= nxt < n and nxt not in visited:
                        visited.add(nxt)
                        q.append(nxt)

                mp[arr[curr]].clear()

            steps += 1

        return -1
```

---

## Dry Run

Input:

```text
arr = [7,6,9,6,9,6,9,7]
```

Start:

```text
Queue = [0]
Steps = 0
```

Jump possibilities:

```text
0 → 1
0 → 7   (same value 7)
```

Reach last index:

```text
0 → 7
```

Answer:

```text
1
```

---

## Complexity Analysis

### Time Complexity

```text
O(n)
```

Each index processed once.

### Space Complexity

```text
O(n)
```

For hashmap + queue + visited set.

---

## Concepts Used

- Graph Traversal
- Breadth First Search (BFS)
- HashMap
- Shortest Path
- Queue



Hence this is the optimal solution.
