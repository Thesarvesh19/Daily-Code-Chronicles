# 3739. Count Subarrays With Majority Element II

## Problem

Given an integer array `nums` and an integer `target`, return the number of subarrays in which `target` is the **majority element**.

A majority element appears **more than half** the number of times in a subarray.

---

## Examples

### Example 1

```text
Input: nums = [1,2,2,1,2], target = 2
Output: 9
```

### Example 2

```text
Input: nums = [1,1,1], target = 2
Output: 0
```

---

# Approach 1: Prefix Sum + Fenwick Tree (Binary Indexed Tree)

### Intuition

A subarray has `target` as its majority element if:

```text
count(target) > count(other elements)
```

Transform the array:

* `target` → `+1`
* every other element → `-1`

Now every subarray becomes a sequence of `+1` and `-1`.

The condition becomes:

```text
Subarray Sum > 0
```

Instead of checking every subarray, maintain prefix sums.

For every current prefix sum `P`, we need the number of previous prefix sums that are **smaller than `P`**.

A **Fenwick Tree (Binary Indexed Tree)** efficiently supports:

* Update prefix frequency
* Query count of smaller prefix sums

both in **O(log n)** time.

---

## Algorithm

1. Convert every element:

   * target → +1
   * others → -1
2. Compute running prefix sum.
3. Store frequencies of previous prefix sums using a Fenwick Tree.
4. For each prefix:

   * Count previous prefix sums smaller than the current one.
   * Add the result to the answer.
   * Insert the current prefix into the tree.
5. Return the total count.

---

## Complexity Analysis

* **Time Complexity:** `O(n log n)`
* **Space Complexity:** `O(n)`

---

# Approach 2: Merge Sort Counting

Instead of a Fenwick Tree, use a modified merge sort to count pairs of prefix sums satisfying:

```text
prefix[j] > prefix[i]
```

during the merge process.

### Complexity

* **Time Complexity:** `O(n log n)`
* **Space Complexity:** `O(n)`

---

# Approach 3: Ordered Set (PBDS)

Using GNU Policy-Based Data Structures (PBDS), maintain all previous prefix sums inside an ordered set.

For every prefix sum:

* Count how many stored prefix sums are smaller.
* Insert the current prefix sum.

### Complexity

* **Time Complexity:** `O(n log n)`
* **Space Complexity:** `O(n)`

---

# Approach 4: Brute Force

Check every possible subarray.

For each subarray:

* Increase score by `1` if the element equals `target`.
* Otherwise decrease score by `1`.
* If the final score is positive, count the subarray.

### Complexity

* **Time Complexity:** `O(n²)`
* **Space Complexity:** `O(1)`

---

# Approach 5: Prefix Sum + Brute Force

Build the transformed prefix sum array first.

For every pair `(i, j)`:

```text
prefix[j] - prefix[i] > 0
```

If true, the subarray is valid.

### Complexity

* **Time Complexity:** `O(n²)`
* **Space Complexity:** `O(n)`

---

# Summary

| Approach                  | Time           | Space | Accepted         |
| ------------------------- | -------------- | ----- | ---------------- |
| Prefix Sum + Fenwick Tree | **O(n log n)** | O(n)  | ✅                |
| Merge Sort Counting       | **O(n log n)** | O(n)  | ✅                |
| Ordered Set (PBDS)        | **O(n log n)** | O(n)  | ✅ (GNU C++ only) |
| Brute Force               | O(n²)          | O(1)  | ❌ TLE            |
| Prefix Sum + Brute Force  | O(n²)          | O(n)  | ❌ TLE            |

---

## Key Takeaways

* Transform the problem into counting **positive-sum subarrays**.
* Prefix sums eliminate repeated calculations.
* Fenwick Tree efficiently counts previous smaller prefix sums.
* The optimal solution runs in **O(n log n)** and is accepted for all constraints.

---

**Topics:** Prefix Sum, Fenwick Tree (Binary Indexed Tree), Binary Search, Merge Sort, Ordered Set, Data Structures
