# Grid Partition with Equal Sum

## Problem
Given a 2D grid of integers, determine whether it is possible to split the grid into two parts such that:

- The sum of elements in both parts is equal  
- The split can be either **horizontal** or **vertical**

Additionally, in some cases, removing **at most one element** from either side is allowed to make the sums equal.

---

## Approach

We solve the problem efficiently without brute force by using:

- Prefix sums
- Hashmaps (frequency counting)

---

### 1. Horizontal Split

We iterate row by row and maintain:

- `s1` → sum of the top partition  
- `s2` → sum of the bottom partition  

We also maintain two hashmaps:

- `cnt1` → frequency of elements in top part  
- `cnt2` → frequency of elements in bottom part  

At every possible cut:

#### Case 1: Direct match
If:

s1 == s2

→ Valid partition found

#### Case 2: Remove one element
If sums differ:

- Compute difference:

diff = abs(s1 - s2)


- Check if this `diff` exists in the heavier partition using hashmap

- Validate edge constraints (boundary conditions)

---

### 2. Vertical Split

Instead of writing separate logic:

- Transpose the grid  
- Apply the same function again  

This keeps the solution clean and avoids duplication

---

## Key Insight

- We never simulate all splits explicitly  
- We track sums dynamically  
- Hashmaps allow **O(1)** lookup for balancing element  

---

## Complexity

Time: O(m × n)  
Space: O(m × n)

---

## Why This Works

- Each element is processed once per direction  
- Efficient difference handling using frequency maps  
- Avoids brute force partition checking  

---

## Implementations

This repository includes solutions in:

- Python (`solution_final.py`)
- Java (`solution.java`)
- C (`solution.c`)

All implementations follow the same optimized logic using prefix sums and hashmap-based validation.

---

## Summary

- Smart use of prefix sums reduces repeated computation  
- Hashmaps enable quick balancing checks  
- Transpose trick avoids duplicate logic  

This results in an efficient and clean solution to a tricky partition problem.
