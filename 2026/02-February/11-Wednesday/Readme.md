# 3719. Longest Balanced Subarray II

## 🧩 Problem Statement

A subarray is called **balanced** if the number of distinct odd numbers equals the number of distinct even numbers.

Return the length of the longest balanced subarray.

### Constraints
- 1 ≤ nums.length ≤ 10^5
- 1 ≤ nums[i] ≤ 10^5

---

## 💡 Approach

### Key Insight

We transform the problem into a **prefix balance problem**:

- Each distinct **odd** number contributes `+1`
- Each distinct **even** number contributes `-1`

We maintain:

- A prefix balance (`now`)
- A `last` map to track the last position of each number
- A **Segment Tree** to:
  - Perform range updates (add/remove contribution)
  - Query the earliest index with the same prefix balance

When the same prefix balance appears again,
the subarray between those indices is balanced.

---

## 🏗 Data Structures Used

- `HashMap` → track last occurrence
- `Segment Tree` → range add + prefix search
- Lazy propagation for efficient updates

---

## ⏱ Complexity

- **Time Complexity:** O(n log n)
- **Space Complexity:** O(n)

---

## 🚀 Why Segment Tree?

Distinct counting is not reversible like prefix sums.

When a number repeats:
- We must remove its previous contribution.
- This requires efficient range updates.

Segment Tree enables:
- O(log n) range modification
- O(log n) prefix balance query

---

## 🏆 Result

Efficiently handles up to 10^5 elements without TLE.
