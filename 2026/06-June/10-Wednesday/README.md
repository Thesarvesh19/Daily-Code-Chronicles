# LeetCode 3691 - Maximum Total Subarray Value II

## Problem Overview

Given an integer array `nums` and an integer `k`, the value of a subarray is defined as:

value = maximum element - minimum element

The objective is to find the sum of the `k` largest subarray values.

Since an array of length `n` contains:

n × (n + 1) / 2

subarrays, generating every subarray and sorting their values would be too expensive for large constraints.

This solution uses:

- Sparse Table for Range Maximum Queries
- Sparse Table for Range Minimum Queries
- Priority Queue (Max Heap)

to efficiently obtain the answer.

---

## Intuition

For every subarray:

```cpp
value = max(subarray) - min(subarray);
```

A brute-force solution would:

1. Generate all subarrays.
2. Compute max and min for each subarray.
3. Store all values.
4. Sort them.
5. Sum the largest k values.

This requires O(n²) subarrays and becomes impractical.

Instead, we need:

- Fast range maximum queries.
- Fast range minimum queries.
- A way to repeatedly obtain the largest remaining candidate.

---

## Data Structures Used

### 1. Sparse Table

Two Sparse Tables are maintained:

#### Maximum Sparse Table

```cpp
maxST[i][j]
```

Stores the maximum value in the interval:

```cpp
[i, i + 2^j - 1]
```

#### Minimum Sparse Table

```cpp
minST[i][j]
```

Stores the minimum value in the interval:

```cpp
[i, i + 2^j - 1]
```

After preprocessing:

- Range Maximum Query = O(1)
- Range Minimum Query = O(1)

---

### 2. Logarithm Table

```cpp
vector<int> logTable;
```

Stores:

```cpp
floor(log2(i))
```

for every length.

This helps identify the largest power of two that fits inside any interval.

---

### 3. Priority Queue

A max heap stores:

```cpp
(value, left, right)
```

where:

```cpp
value = max(nums[left...right]) - min(nums[left...right])
```

The heap always returns the largest currently available subarray value.

---

## Sparse Table Construction

### Initialization

Intervals of length 1:

```cpp
for (int i = 0; i < n; i++) {
    maxST[i][0] = nums[i];
    minST[i][0] = nums[i];
}
```

Each element is both the maximum and minimum of its own interval.

---

### Building Larger Intervals

For every power of two:

```cpp
2^j
```

we combine two intervals of size:

```cpp
2^(j-1)
```

Maximum Table:

```cpp
maxST[i][j] =
max(
    maxST[i][j-1],
    maxST[i + (1 << (j-1))][j-1]
);
```

Minimum Table:

```cpp
minST[i][j] =
min(
    minST[i][j-1],
    minST[i + (1 << (j-1))][j-1]
);
```
## Range Query Function

The helper function:

```cpp
getRangeValue(l, r)
```

returns:

```cpp
max(nums[l...r]) - min(nums[l...r])
```

### Step 1: Compute Length

```cpp
int len = r - l + 1;
```

### Step 2: Find Largest Power of Two

```cpp
int j = logTable[len];
```

### Step 3: Query Maximum

```cpp
int mx =
max(
    maxST[l][j],
    maxST[r - (1 << j) + 1][j]
);
```

### Step 4: Query Minimum

```cpp
int mn =
min(
    minST[l][j],
    minST[r - (1 << j) + 1][j]
);
```

### Step 5: Return Value

```cpp
return (long long)mx - mn;
```

Since Sparse Table queries are constant time:

```text
Time Complexity = O(1)
```

---

## Heap Initialization

For every starting index:

```cpp
l = 0 ... n-1
```

the interval:

```cpp
[l, n-1]
```

is inserted into the heap.

```cpp
for (int l = 0; l < n; l++) {
    pq.push({
        getRangeValue(l, n - 1),
        l,
        n - 1
    });
}
```

This gives one candidate interval for every left boundary.

---

## Processing the Largest K Values

We repeat exactly k times.

### Extract Best Candidate

```cpp
auto [val, l, r] = pq.top();
pq.pop();
```

Because it is a max heap:

```cpp
val
```

is the largest available subarray value.

---

### Add Contribution

```cpp
totalSum += val;
```

This contributes to the final answer.

---

### Generate Next Candidate

If:

```cpp
r > l
```

then a shorter interval:

```cpp
[l, r-1]
```

is created.

```cpp
pq.push({
    getRangeValue(l, r - 1),
    l,
    r - 1
});
```

This allows the algorithm to continue exploring intervals starting at the same left boundary.

---

## Why Does This Work?

For every left boundary:

```cpp
l
```

we create the sequence:

```text
[l,n−1]
[l,n−2]
[l,n−3]
...
[l,l]
```

The heap always stores the largest unexplored candidate from every sequence.

Whenever the best interval is selected, the next interval from the same sequence is inserted.

Thus:

- No candidate is missed.
- Intervals are explored in decreasing order of priority.
- The largest available value is always chosen.

Preprocessing Complexity:

```text
O(n log n)
```
