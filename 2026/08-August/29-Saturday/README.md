# LeetCode 2948 - Make Lexicographically Smallest Array by Swapping Elements

## Problem

You are given an array `nums` and an integer `limit`.

You can swap two elements `nums[i]` and `nums[j]` if:

```text
|nums[i] - nums[j]| <= limit
```

You can perform any number of valid swaps.

Return the **lexicographically smallest array** that can be obtained.

---

## Approach

The main observation is that elements can be connected through a chain of valid swaps.

First, create pairs containing:

```text
(value, original_index)
```

and sort them by value.

For example:

```text
nums = [5, 3, 9, 1]
limit = 2
```

After sorting:

```text
(1, 3), (3, 1), (5, 0), (9, 2)
```

The values `1`, `3`, and `5` belong to the same group because:

```text
3 - 1 <= 2
5 - 3 <= 2
```

Therefore, these values can be rearranged among their original positions.

To make the result lexicographically smallest:

1. Find each connected group.
2. Extract the original indices of that group.
3. Sort the indices.
4. Assign the group's smallest values to the smallest indices.

---

## Algorithm

1. Store every element as `(value, index)`.
2. Sort all pairs by value.
3. Traverse the sorted pairs and divide them into groups.
4. Two consecutive elements belong to the same group if their value difference is at most `limit`.
5. For each group:

   * Collect its original indices.
   * Sort the indices.
   * Assign the group's values, already sorted, to those indices in increasing order.
6. Return the resulting array.

---

## Example

### Input

```text
nums = [5, 3, 9, 1]
limit = 2
```

### Sorted pairs

```text
(1, 3)
(3, 1)
(5, 0)
(9, 2)
```

Groups:

```text
Group 1:
Values  = [1, 3, 5]
Indices = [0, 1, 3]

Group 2:
Values  = [9]
Indices = [2]
```

Assign the smallest values to the smallest indices:

```text
Index 0 -> 1
Index 1 -> 3
Index 3 -> 5
Index 2 -> 9
```

### Output

```text
[1, 3, 9, 5]
```

---

## C++ Solution

```cpp
class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();

        vector<pair<int, int>> arr;

        for (int i = 0; i < n; i++) {
            arr.push_back({nums[i], i});
        }

        sort(arr.begin(), arr.end());

        vector<int> ans(n);
        int i = 0;

        while (i < n) {
            int j = i;

            while (j + 1 < n &&
                   arr[j + 1].first - arr[j].first <= limit) {
                j++;
            }

            vector<int> indices;

            for (int k = i; k <= j; k++) {
                indices.push_back(arr[k].second);
            }

            sort(indices.begin(), indices.end());

            for (int k = 0; k < indices.size(); k++) {
                ans[indices[k]] = arr[i + k].first;
            }

            i = j + 1;
        }

        return ans;
    }
};
```

---

## Java Solution

```java
import java.util.*;

class Solution {
    public int[] lexicographicallySmallestArray(int[] nums, int limit) {
        int n = nums.length;

        int[][] arr = new int[n][2];

        for (int i = 0; i < n; i++) {
            arr[i][0] = nums[i];
            arr[i][1] = i;
        }

        Arrays.sort(arr, (a, b) -> Integer.compare(a[0], b[0]));

        int[] ans = new int[n];

        int i = 0;

        while (i < n) {
            int j = i;

            while (j + 1 < n &&
                   arr[j + 1][0] - arr[j][0] <= limit) {
                j++;
            }

            int size = j - i + 1;
            int[] indices = new int[size];

            for (int k = 0; k < size; k++) {
                indices[k] = arr[i + k][1];
            }

            Arrays.sort(indices);

            for (int k = 0; k < size; k++) {
                ans[indices[k]] = arr[i + k][0];
            }

            i = j + 1;
        }

        return ans;
    }
}
```

---

## Python Solution

```python
class Solution:
    def lexicographicallySmallestArray(self, nums, limit):
        n = len(nums)

        arr = sorted((value, index) for index, value in enumerate(nums))

        ans = [0] * n
        i = 0

        while i < n:
            j = i

            while j + 1 < n and arr[j + 1][0] - arr[j][0] <= limit:
                j += 1

            values = [arr[k][0] for k in range(i, j + 1)]
            indices = sorted(arr[k][1] for k in range(i, j + 1))

            for index, value in zip(indices, values):
                ans[index] = value

            i = j + 1

        return ans
```

---

## Complexity Analysis

Let `n` be the length of `nums`.

### Time Complexity

Sorting all `(value, index)` pairs takes:

```text
O(n log n)
```

Sorting the indices of all groups takes at most:

```text
O(n log n)
```

Therefore:

```text
O(n log n)
```

### Space Complexity

We store the sorted pairs, answer array, and temporary group indices:

```text
O(n)
```

---

## Key Insight

The crucial idea is:

> If consecutive values in sorted order differ by at most `limit`, they can belong to the same swappable connected component.

Once a group is identified, its values can be freely rearranged among its original positions. To minimize the complete array lexicographically, simply place the smallest values at the smallest original indices.

**Time:** `O(n log n)`
**Space:** `O(n)`
