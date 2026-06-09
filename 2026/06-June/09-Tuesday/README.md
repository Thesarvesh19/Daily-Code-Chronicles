# 3689. Maximum Total Subarray Value I

## Problem Statement
 
Given an integer array `nums` and an integer `k`, determine the maximum total value obtainable by selecting exactly `k` subarrays.

The value of a subarray is defined as:

```text
max(subarray) - min(subarray)
```

The same subarray can be selected multiple times, and overlapping subarrays are allowed.

---

## Intuition

To maximize the total value, we first need to maximize the value of a single subarray.

A subarray's value depends only on the difference between its maximum and minimum elements. Therefore, the largest possible value is achieved when the subarray contains both:

* The maximum element in the array
* The minimum element in the array

Thus, the maximum subarray value is:

```text
max(nums) - min(nums)
```

Since the same subarray can be chosen multiple times, we simply select this optimal subarray `k` times.

---

## Algorithm

1. Find the minimum element in `nums`.
2. Find the maximum element in `nums`.
3. Compute their difference.
4. Multiply the difference by `k`.
5. Return the result.

---

## Correctness Proof

Let:

```text
M = max(nums)
m = min(nums)
```

For any subarray:

```text
max(subarray) ≤ M
min(subarray) ≥ m
```

Therefore:

```text
max(subarray) - min(subarray) ≤ M - m
```

This shows that no subarray can have a value greater than:

```text
M - m
```

Since the same subarray may be selected repeatedly, choosing the subarray with value:

```text
M - m
```

exactly `k` times produces the maximum possible total value:

```text
(M - m) × k
```

Hence, the algorithm is optimal.

---

## Complexity Analysis

### Time Complexity

```text
O(n)
```

We scan the array once to find the minimum and maximum values.

### Space Complexity

```text
O(1)
```

Only a few variables are used.

---

## Example

### Input

```text
nums = [1, 5, 2, 8]
k = 3
```

### Calculation

```text
max(nums) = 8
min(nums) = 1

Maximum Subarray Value = 8 - 1 = 7
Answer = 7 × 3 = 21
```

### Output

```text
21
```

---

## Key Observation

Because repeated selection of the same subarray is allowed, the problem reduces to finding the maximum possible subarray value once and multiplying it by `k`.

---

## Tags

* Array
* Greedy
* Math
* Simulation
