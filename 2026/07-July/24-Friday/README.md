# 3514. Number of Unique XOR Triplets

## Overview

This repository contains a solution for **LeetCode 3514 – Number of Unique XOR Triplets**.

The objective is to determine how many **distinct XOR values** can be obtained by selecting triplets from the given array. The solution efficiently computes all possible pairwise XOR values and then combines them with every array element to generate all unique triplet XOR results.

---

## Approach

The algorithm works in two stages:

1. Compute the XOR value for every unique pair of elements and store the results in a hash set.
2. XOR each stored pair value with every element in the array.
3. Store every generated triplet XOR value in another hash set.
4. Return the size of the second hash set as the answer.

Using hash sets automatically removes duplicate XOR values.

---

## Algorithm

1. Handle the edge case where the array contains only one element.
2. Generate all unique pair XOR values.
3. Store pair XORs in a hash set.
4. Combine each pair XOR with every array element.
5. Store resulting XOR values in another hash set.
6. Return the number of distinct values.

---

## Complexity Analysis

| Complexity | Value |
|------------|-------|
| Time | **O(n²)** |
| Space | **O(n²)** |

---

## Features

- Efficient hash-set based solution.
- Eliminates duplicate XOR values automatically.
- Handles edge cases correctly.
- Clean and easy-to-understand implementation.
- Available in multiple programming languages.

---

## Supported Languages

- Python
- Java
- C++
- C
- C#

---

## Key Concepts

- Bitwise XOR
- Hash Set
- Pair Enumeration
- Triplet Generation
- Duplicate Elimination

---

## Conclusion

The solution efficiently finds all distinct XOR values obtainable from triplets by first computing pair XOR values and then extending them with every element in the array. Using hash sets ensures uniqueness while keeping the implementation straightforward and efficient.
