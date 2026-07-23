# 3513. Number of Unique XOR Triplets I

## Problem Overview

You are given an integer array `nums`. A **triplet** consists of three indices `(i, j, k)` where repetition of indices is allowed according to the problem statement. For every possible triplet, compute the XOR of the selected values and determine how many **distinct XOR results** can be obtained.

Return the total number of unique XOR triplet values.

---

## Key Observation

The answer depends **only on the length of the array**.

- If the array contains only **1 or 2 elements**, the number of unique XOR triplets is simply the array length.
- If the array contains **3 or more elements**, every XOR value in a complete binary range becomes achievable.
- Therefore, the answer is the **smallest power of two strictly greater than `n - 1`**, which can be computed as:

```text
1 << bit_length(n)
```

where `n` is the length of the array.

---

## Algorithm

1. Compute the length `n` of the array.
2. If `n <= 2`, return `n`.
3. Otherwise:
   - Find the number of bits required to represent `n`.
   - Return `2^(number of bits)`.

---

## Correctness

- Arrays of size `1` and `2` cannot generate additional unique XOR values.
- For arrays of size `3` or more, XOR combinations cover an entire binary interval.
- The total number of distinct values equals the next power of two determined by the binary length of `n`.

Thus, the algorithm always produces the correct answer.

---

## Complexity Analysis

| Metric | Complexity |
|--------|------------|
| Time | **O(1)** |
| Space | **O(1)** |

---

## Implementations

This repository includes optimized solutions in:

- Python
- C
- C++
- Java
- C#

All implementations follow the same constant-time mathematical approach.

---

## Example

### Input

```text
nums = [1,2,3]
```

### Output

```text
4
```

### Explanation

The distinct XOR triplet values form a complete range of four values, so the answer is **4**.

---

## Highlights

- Constant-time solution
- Constant auxiliary space
- Mathematical observation instead of brute force
- Suitable for very large input sizes
- Clean and efficient implementation
