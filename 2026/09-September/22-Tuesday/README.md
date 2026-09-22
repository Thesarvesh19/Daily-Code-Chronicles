# LeetCode 3525 - Find X Value of Array II

## Problem

You are given an array `nums`, an integer `k`, and a 2D array `queries`.

Each query is represented as:

```text
[index, value, start, x]
```

For every query:

1. Update `nums[index]` to `value`.
2. Consider the subarray `nums[start ... n-1]`.
3. Consider every non-empty prefix of this subarray.
4. Count how many of those prefixes have a product whose remainder modulo `k` is equal to `x`.

Return the answer for every query.

---

## Example

### Input

```text
nums = [1, 2, 3, 4, 5]
k = 3
queries = [[2, 2, 0, 2], [3, 3, 3, 0], [0, 1, 0, 1]]
```

### Output

```text
[2, 2, 2]
```

---

# Key Observation

For a query:

```text
[index, value, start, x]
```

we first perform:

```text
nums[index] = value
```

Then we consider:

```text
nums[start ... n-1]
```

Since we are interested in every possible prefix of this range, we need to count prefixes according to their product modulo `k`.

A direct solution would scan the entire range for every query, which is too slow.

Therefore, we use a **Segment Tree**.

---

# Segment Tree Idea

For every segment of the array, store:

1. `prod`
2. `cnt`

## 1. prod

`prod` is the product of all elements in the segment modulo `k`.

For example:

```text
nums = [2, 3, 4]
k = 5
```

Then:

```text
prod = (2 * 3 * 4) % 5
     = 24 % 5
     = 4
```

---

## 2. cnt

`cnt[r]` represents the number of non-empty prefixes of the segment whose product modulo `k` equals `r`.

For example:

```text
nums = [2, 3]
k = 5
```

The prefixes are:

```text
[2]
[2, 3]
```

Their products modulo `5` are:

```text
2 % 5 = 2
(2 * 3) % 5 = 1
```

Therefore:

```text
cnt[1] = 1
cnt[2] = 1
```

---

# Merging Two Nodes

Suppose a segment is divided into:

```text
Left + Right
```

Let:

```text
left.prod
right.prod
```

be the products of the two segments modulo `k`.

The product of the complete segment is:

```text
parent.prod = (left.prod * right.prod) % k
```

For the prefix counts:

### Prefixes completely inside the left segment

These are already stored in:

```text
left.cnt
```

So we copy them.

### Prefixes that continue into the right segment

Suppose a prefix of the right segment has product remainder `r`.

After including the complete left segment, its remainder becomes:

```text
(left.prod * r) % k
```

Therefore:

```text
parent.cnt[(left.prod * r) % k] += right.cnt[r]
```

Because `k <= 5`, each merge takes only `O(k)` time.

---

# Leaf Node

For a single element:

```text
value = nums[i] % k
```

The segment contains exactly one non-empty prefix.

Therefore:

```text
prod = value
cnt[value] = 1
```

---

# Query Processing

For every query:

```text
[index, value, start, x]
```

we perform two operations.

## Step 1: Point Update

Update:

```text
nums[index] = value
```

in the segment tree.

---

## Step 2: Range Query

Query:

```text
[start, n - 1]
```

The resulting node contains the number of prefixes having every possible remainder.

Therefore, the answer is:

```text
result.cnt[x]
```

---

# Why Segment Tree?

Without a segment tree, every query could require `O(n)` work.

With a segment tree:

- Point update: `O(k log n)`
- Range query: `O(k log n)`
- Merge: `O(k)`

Since:

```text
k <= 5
```

the solution is efficient.

---

# Algorithm

1. Build a segment tree over `nums`.
2. Store the product modulo `k` and prefix counts for every node.
3. For every query:
   - Update `nums[index]` to `value`.
   - Query the range `[start, n - 1]`.
   - Take `cnt[x]` from the resulting node.
4. Return all answers.

---

# Complexity

Let:

```text
n = nums.length
q = queries.length
```

and:

```text
k <= 5
```

### Building

```text
O(n * k)
```

### Each Update

```text
O(k * log n)
```

### Each Query

```text
O(k * log n)
```

### Total

```text
O(n * k + q * k * log n)
```

Since `k <= 5`, this is effectively:

```text
O(n + q log n)
```

with a small constant factor.

### Space

```text
O(n * k)
```

---

# Java Solution

```java
import java.util.Arrays;

class Solution {

    class Node {
        int prod;
        int[] cnt;

        Node(int k) {
            prod = 1 % k;
            cnt = new int[k];
        }
    }

    int k;
    Node[] tree;

    // Merge two segment tree nodes
    Node merge(Node left, Node right) {

        Node result = new Node(k);

        // Product of the complete segment
        result.prod = (left.prod * right.prod) % k;

        // Prefixes completely inside the left segment
        for (int i = 0; i < k; i++) {
            result.cnt[i] = left.cnt[i];
        }

        // Prefixes that cross from left into right
        for (int r = 0; r < k; r++) {
            int newRemainder = (left.prod * r) % k;
            result.cnt[newRemainder] += right.cnt[r];
        }

        return result;
    }

    // Build the segment tree
    void build(int node, int left, int right, int[] nums) {

        tree[node] = new Node(k);

        // Leaf node
        if (left == right) {

            int value = nums[left] % k;

            tree[node].prod = value;
            tree[node].cnt[value] = 1;

            return;
        }

        int mid = left + (right - left) / 2;

        build(node * 2, left, mid, nums);
        build(node * 2 + 1, mid + 1, right, nums);

        tree[node] = merge(
            tree[node * 2],
            tree[node * 2 + 1]
        );
    }

    // Point update
    void update(
        int node,
        int left,
        int right,
        int index,
        int value
    ) {

        // Leaf node
        if (left == right) {

            value %= k;

            tree[node] = new Node(k);

            tree[node].prod = value;
            tree[node].cnt[value] = 1;

            return;
        }

        int mid = left + (right - left) / 2;

        if (index <= mid) {

            update(
                node * 2,
                left,
                mid,
                index,
                value
            );

        } else {

            update(
                node * 2 + 1,
                mid + 1,
                right,
                index,
                value
            );
        }

        tree[node] = merge(
            tree[node * 2],
            tree[node * 2 + 1]
        );
    }

    // Range query
    Node query(
        int node,
        int left,
        int right,
        int queryLeft,
        int queryRight
    ) {

        // Completely inside query range
        if (
            queryLeft <= left &&
            right <= queryRight
        ) {
            return tree[node];
        }

        int mid = left + (right - left) / 2;

        // Completely in left child
        if (queryRight <= mid) {

            return query(
                node * 2,
                left,
                mid,
                queryLeft,
                queryRight
            );
        }

        // Completely in right child
        if (queryLeft > mid) {

            return query(
                node * 2 + 1,
                mid + 1,
                right,
                queryLeft,
                queryRight
            );
        }

        // Query overlaps both children
        Node leftResult = query(
            node * 2,
            left,
            mid,
            queryLeft,
            queryRight
        );

        Node rightResult = query(
            node * 2 + 1,
            mid + 1,
            right,
            queryLeft,
            queryRight
        );

        return merge(leftResult, rightResult);
    }

    public int[] resultArray(
        int[] nums,
        int k,
        int[][] queries
    ) {

        this.k = k;

        int n = nums.length;

        // Segment tree
        tree = new Node[4 * n + 5];

        // Build tree
        build(
            1,
            0,
            n - 1,
            nums
        );

        int[] answer = new int[queries.length];

        for (int i = 0; i < queries.length; i++) {

            int index = queries[i][0];
            int value = queries[i][1];
            int start = queries[i][2];
            int x = queries[i][3];

            // Update nums[index]
            update(
                1,
                0,
                n - 1,
                index,
                value
            );

            // Query range [start, n - 1]
            Node result = query(
                1,
                0,
                n - 1,
                start,
                n - 1
            );

            // Number of prefixes whose
            // product modulo k equals x
            answer[i] = result.cnt[x];
        }

        return answer;
    }
}
```

---

# Important Implementation Details

## 1. Correct LeetCode Method Signature

The method must be:

```java
public int[] resultArray(
    int[] nums,
    int k,
    int[][] queries
)
```

Do not use:

```java
numberOfWays()
```

That belongs to a different LeetCode problem.

---

## 2. Point Updates Persist

If one query changes:

```text
nums[index] = value
```

that modification remains for all subsequent queries.

The segment tree maintains the updated array automatically.

---

## 3. Zero-Based Indexing

Java arrays are zero-indexed.

Therefore:

```text
nums[0]
nums[1]
nums[2]
...
```

The segment tree in this solution also uses zero-based indexing.

---

## 4. No Main Method Required

LeetCode automatically creates the `Solution` object and calls:

```java
resultArray(nums, k, queries)
```

Therefore, do not add:

```java
public static void main(String[] args)
```

when submitting to LeetCode.

---

# Final Summary

The solution uses a **Segment Tree**.

Each node stores:

```text
prod
cnt[0 ... k-1]
```

where:

```text
prod = product of the entire segment modulo k
```

and:

```text
cnt[x] = number of non-empty prefixes
         whose product modulo k equals x
```

The merge operation combines the left and right segments in `O(k)` time.

Each query performs:

```text
1. Point update
2. Range query
3. Read cnt[x]
```

This gives an efficient solution with:

```text
Time:  O(n*k + q*k*log(n))
Space: O(n*k)
```

Since `k <= 5`, the solution is efficient for the given constraints.
