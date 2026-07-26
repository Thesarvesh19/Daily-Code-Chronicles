# 628. Maximum Product of Three Numbers

## Problem Statement

Given an integer array `nums`, return the **maximum product** that can be obtained by multiplying any **three numbers** from the array.

## Approach

The key observation is that the maximum product can come from one of two possibilities:

1. **The three largest numbers** in the array.
2. **The two smallest (most negative) numbers** and the largest positive number.

Since multiplying two negative numbers results in a positive number, the second case can sometimes produce a larger product.

### Algorithm

1. Sort the array in non-decreasing order.
2. Compute:
   - Product of the three largest numbers.
   - Product of the two smallest numbers and the largest number.
3. Return the larger of the two products.

## Correctness

After sorting:

- The three largest values are located at the end of the array.
- The two smallest values are located at the beginning.
- Every possible maximum product must be one of these two combinations.

Therefore, taking the maximum of these two products always produces the correct answer.

## Complexity Analysis

- **Time Complexity:** `O(n log n)` (sorting the array)
- **Space Complexity:** `O(1)` (excluding the sorting algorithm's internal space)

## Example

### Input

```text
nums = [1,2,3,4]
```

### Output

```text
24
```

### Explanation

The maximum product is:

```text
2 × 3 × 4 = 24
```

---

### Input

```text
nums = [-10,-10,5,2]
```

### Output

```text
500
```

### Explanation

```text
(-10) × (-10) × 5 = 500
```

which is greater than:

```text
5 × 2 × (-10) = -100
```



---

**LeetCode Problem:** 628. Maximum Product of Three Numbers
