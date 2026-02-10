# 3719. Longest Balanced Subarray I

## Problem Statement
Given an integer array `nums`, a subarray is called **balanced** if:
- the number of **distinct even numbers**
- equals the number of **distinct odd numbers**

Return the length of the **longest balanced subarray**.

---

## Approach

### Brute Force with Distinct Tracking

Since the constraint is small (`nums.length ≤ 1500`), we can safely use an `O(n²)` approach.

For every starting index:
- expand the subarray to the right
- track **distinct even numbers** using a set
- track **distinct odd numbers** using another set
- whenever both set sizes are equal, update the maximum length

---

## Algorithm
1. Iterate over all possible starting indices.
2. Initialize two empty sets: `evenSet` and `oddSet`.
3. Expand the subarray while updating the sets.
4. Check if `evenSet.size() == oddSet.size()`.
5. Track the maximum valid subarray length.

---

## Complexity Analysis
- **Time Complexity:** `O(n²)`
- **Space Complexity:** `O(n)` (sets for distinct values)

---

## Implementations
- `solution.py` → Python implementation
- `Solution.java` → Java implementation

Both follow the same logic and are fully LeetCode-compatible.
