# 3867. Sum of GCD of Formed Pairs

## Problem

You are given an integer array `nums`.

Construct a new array by processing the elements from left to right:

* Keep track of the maximum value seen so far.
* For each element, compute the Greatest Common Divisor (GCD) between the current element and the current maximum.
* Store these GCD values in a new array.

After constructing the array:

1. Sort it in non-decreasing order.
2. Pair the smallest element with the largest, the second smallest with the second largest, and so on.
3. Compute the GCD of every pair.
4. Return the sum of all these GCD values.

---

# Intuition

Instead of working directly with the original numbers, we first transform them into a GCD-based array.

Each transformed value depends only on:

* the current number
* the maximum value encountered so far

After transformation, sorting allows us to easily create the required smallest-largest pairing.

Finally, we compute the GCD of every pair and accumulate the result.

---

# Approach

### Step 1

Maintain the maximum value encountered while traversing the array.

### Step 2

For every element:

* update the current maximum
* calculate

```
gcd(currentNumber, currentMaximum)
```

Store the result.

### Step 3

Sort the transformed array.

### Step 4

Use two pointers:

* left starts from the beginning
* right starts from the end

For every pair:

```
answer += gcd(leftValue, rightValue)
```

Move both pointers inward until they meet.

---

# Algorithm

1. Initialize `currentMax = 0`.
2. Create an empty transformed array.
3. Traverse `nums`.
4. Update `currentMax`.
5. Store `gcd(nums[i], currentMax)`.
6. Sort the transformed array.
7. Use two pointers.
8. Add the GCD of every pair.
9. Return the answer.

---

# Example

### Input

```
nums = [6, 9, 12, 15]
```

### Transformation

Current maximums

```
6
9
12
15
```

Transformed array

```
gcd(6,6)=6
gcd(9,9)=9
gcd(12,12)=12
gcd(15,15)=15

=> [6,9,12,15]
```

Sorted

```
[6,9,12,15]
```

Pairs

```
(6,15)
(9,12)
```

GCD values

```
3
3
```

Answer

```
6
```

---

# Correctness

* Every transformed value is computed exactly as required.
* Sorting guarantees correct smallest-largest pairing.
* Every pair contributes exactly one GCD to the answer.
* Therefore the algorithm correctly computes the required sum.

---

# Complexity Analysis

### Time Complexity

Building transformed array

```
O(n)
```

Sorting

```
O(n log n)
```

Pair processing

```
O(n)
```

Overall

```
O(n log n + n log M)
```

where `M` is the maximum value involved in GCD computation.

### Space Complexity

```
O(n)
```

for the transformed array.

---

# Edge Cases

* Minimum input size
* Duplicate values
* Already sorted array
* Reverse sorted array
* Large integers
* All values equal
* GCD equal to 1
* Maximum constraints

---

# Key Observations

* The running maximum can be updated in constant time.
* Euclid's algorithm computes each GCD efficiently.
* Sorting simplifies the required pairing strategy.
* Two pointers provide an efficient linear pass after sorting.

---

