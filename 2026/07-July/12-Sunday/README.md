# 1331. Rank Transform of an Array

![LeetCode](https://img.shields.io/badge/LeetCode-1331-orange)
![Difficulty](https://img.shields.io/badge/Difficulty-Easy-brightgreen)
![Topics](https://img.shields.io/badge/Topics-Sorting%20%7C%20Hash%20Table%20%7C%20Array-blue)

## Problem Statement

Given an integer array `arr`, replace each element with its **rank**.

The rank represents the position of the element in the sorted list of unique values.

The ranking rules are:

- Rank starts from **1**.
- The larger the value, the larger its rank.
- Equal values receive the **same rank**.
- Ranks should be as small as possible.

Return the transformed array.

---

## Examples

### Example 1

**Input**

```text
arr = [40,10,20,30]
```

**Output**

```text
[4,1,2,3]
```

**Explanation**

Sorted unique values:

```text
[10,20,30,40]
```

Ranks:

```text
10 → 1
20 → 2
30 → 3
40 → 4
```

Final transformed array:

```text
[4,1,2,3]
```

---

### Example 2

**Input**

```text
arr = [100,100,100]
```

**Output**

```text
[1,1,1]
```

**Explanation**

Only one unique value exists, so every element receives rank **1**.

---

### Example 3

**Input**

```text
arr = [37,12,28,9,100,56,80,5,12]
```

**Output**

```text
[5,3,4,2,8,6,7,1,3]
```

---

## Constraints

- `0 <= arr.length <= 10^5`
- `-10^9 <= arr[i] <= 10^9`

---

# Approach

The simplest solution is to determine the position of every **unique** value after sorting.

Instead of sorting the entire array and assigning a rank to every occurrence, we first collect all unique values.

The process is:

1. Copy the original array.
2. Sort the copied array.
3. Remove duplicate values.
4. Assign ranks beginning from **1**.
5. Store every value and its rank in a hash map.
6. Traverse the original array and replace every value with its mapped rank.

This guarantees that:

- Equal values always receive the same rank.
- Smaller values always receive smaller ranks.
- Ranks remain consecutive without gaps.

---

# Algorithm

1. Create a copy of the original array.
2. Sort the copied array.
3. Remove duplicate elements.
4. Create a hash map.
5. Assign rank `1` to the smallest unique element.
6. Continue assigning increasing ranks.
7. Traverse the original array.
8. Replace each element with its stored rank.
9. Return the transformed array.

---

# Dry Run

Consider:

```text
arr = [40,10,20,30]
```

### Step 1

Original array

```text
[40,10,20,30]
```

### Step 2

Sorted copy

```text
[10,20,30,40]
```

### Step 3

Assign ranks

| Value | Rank |
|------:|-----:|
| 10 | 1 |
| 20 | 2 |
| 30 | 3 |
| 40 | 4 |

### Step 4

Replace every value

| Original | Rank |
|---------:|-----:|
| 40 | 4 |
| 10 | 1 |
| 20 | 2 |
| 30 | 3 |

Final answer

```text
[4,1,2,3]
```

---

# Why This Works

Sorting the unique values establishes the correct ordering.

Because every unique value receives exactly one rank, duplicate values naturally share the same rank.

Using a hash map allows every lookup to be performed in constant time, making the transformation efficient.

---

# Correctness Proof

Let the sorted unique values be

```text
u1 < u2 < u3 < ... < uk
```

We assign

```text
u1 → 1
u2 → 2
...
uk → k
```

For any two values:

- If they are equal, they reference the same hash map entry and therefore obtain the same rank.
- If `a < b`, then `a` appears before `b` in sorted order, so its assigned rank is smaller.
- Every unique value is assigned exactly one rank.

Therefore, the resulting array satisfies all ranking rules.

Hence, the algorithm is correct.

---

# Complexity Analysis

Let **n** be the length of the array.

### Time Complexity

Sorting:

```text
O(n log n)
```

Creating hash map:

```text
O(n)
```

Transforming the array:

```text
O(n)
```

Overall:

```text
O(n log n)
```

---

### Space Complexity

Sorted copy:

```text
O(n)
```

Hash map:

```text
O(n)
```

Overall:

```text
O(n)
```

---

# Data Structures Used

- Array
- Hash Map
- Sorting

---

# Edge Cases

### Empty array

```text
[]
```

Output

```text
[]
```

---

### Single element

```text
[8]
```

Output

```text
[1]
```

---

### All elements equal

```text
[7,7,7,7]
```

Output

```text
[1,1,1,1]
```

---

### Negative values

```text
[-10,-5,-5,-1]
```

Output

```text
[1,2,2,3]
```

---

### Already sorted

```text
[1,2,3,4]
```

Output

```text
[1,2,3,4]
```

---

### Reverse sorted

```text
[9,8,7,6]
```

Output

```text
[4,3,2,1]
```

---

# Optimizations

- Remove duplicates before assigning ranks.
- Store ranks in a hash map for constant-time lookup.
- Traverse the original array only once after preprocessing.

---

# Topics Covered

- Sorting
- Arrays
- Hash Map
- Coordinate Compression
- Data Structures

---

# Interview Discussion

### Why use a hash map?

To quickly obtain the rank of every value in constant time.

---

### Why remove duplicates?

Duplicate values must receive identical ranks.

---

### Can this be solved without sorting?

Not efficiently. Since ranks depend on the relative order of values, sorting (or an equivalent ordered structure) is required.

---

### Why is the complexity `O(n log n)`?

Sorting dominates the running time. All remaining operations are linear.

---

## Summary

- Sort unique values.
- Assign consecutive ranks.
- Store ranks in a hash map.
- Replace every element using the map.
- Time Complexity: **O(n log n)**
- Space Complexity: **O(n)**

This approach is simple, efficient, easy to understand, and works within the given constraints.
