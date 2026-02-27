# Minimum Operations to Equalize Binary String

##  Problem Summary

You are given a binary string `s` and an integer `k`.

In one operation, you must flip exactly `k` different indices.
Flipping means:
- '0' → '1'
- '1' → '0'

Return the minimum number of operations required to make all characters '1'.
If impossible, return -1.

---

##  Approach

Instead of simulating string operations directly, we model the problem as:

### Key Insight:
The only thing that matters is the **number of zeros** remaining.

Let:
- `cur` = current number of zeros

After flipping exactly `k` indices:
- Some zeros become ones
- Some ones become zeros

The new zero count must lie in a specific range `[l, r]`.

We perform a **BFS over zero counts** from initial count to 0.

---

##  Optimization Used

- Two `TreeSet`s for parity separation
- Avoid revisiting states
- Efficient range queries using `ceiling()`

This ensures we:
- Avoid redundant exploration
- Keep complexity efficient

---

##  Time Complexity

O(n log n)

Because:
- Each zero-count state is visited at most once
- TreeSet operations cost O(log n)

---

##  Space Complexity

O(n)

For storing:
- BFS queue
- TreeSets of possible states
