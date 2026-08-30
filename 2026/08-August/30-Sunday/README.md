# LeetCode 2091 — Removing Minimum and Maximum From Array

## Problem

You are given an array `nums` consisting of distinct integers.

In one operation, you can remove an element from either the beginning or the end of the array.

Find the minimum number of deletions required to remove **both the minimum and maximum elements** from the array.

---

## Approach

First, find the indices of the minimum and maximum elements.

Let:

* `minIdx` = index of the minimum element
* `maxIdx` = index of the maximum element

Ensure that `minIdx < maxIdx`.

There are only **three possible ways** to remove both elements:

### 1. Remove both from the front

We need to remove everything up to `maxIdx`.

```text
maxIdx + 1
```

### 2. Remove both from the back

We need to remove everything from `minIdx` to the end.

```text
n - minIdx
```

### 3. Remove one from each side

Remove the minimum from the front and maximum from the back:

```text
(minIdx + 1) + (n - maxIdx)
```

The answer is the minimum of these three possibilities.

---

## C++ Solution

```cpp
class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        int minIdx = 0, maxIdx = 0;

        // Find indices of minimum and maximum
        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[minIdx])
                minIdx = i;

            if (nums[i] > nums[maxIdx])
                maxIdx = i;
        }

        // Ensure minIdx comes before maxIdx
        if (minIdx > maxIdx)
            swap(minIdx, maxIdx);

        // Remove both from the front
        int front = maxIdx + 1;

        // Remove both from the back
        int back = n - minIdx;

        // Remove min from front and max from back
        int both = (minIdx + 1) + (n - maxIdx);

        return min({front, back, both});
    }
};
```

---

## Example

### Input

```text
nums = [2, 10, 7, 5, 4, 1, 8, 6]
```

Minimum element:

```text
1 → index 5
```

Maximum element:

```text
10 → index 1
```

After ordering the indices:

```text
minIdx = 1
maxIdx = 5
```

Possible operations:

```text
Front:  maxIdx + 1 = 6

Back:   n - minIdx = 7

Both:   (minIdx + 1) + (n - maxIdx)
      = 2 + 3
      = 5
```

Therefore:

```text
Answer = min(6, 7, 5) = 5
```

---

## Complexity

* **Time Complexity:** `O(n)`
* **Space Complexity:** `O(1)`

The array is scanned only once to find the minimum and maximum indices.

---

## Key Idea

The important observation is that because elements can only be removed from the **front or back**, the minimum and maximum can be removed in only three useful ways:

```text
Both from front
Both from back
One from each side
```

Taking the minimum of these three possibilities gives the optimal answer.
