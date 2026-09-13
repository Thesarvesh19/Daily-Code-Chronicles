# LeetCode 835 — Image Overlap

## Problem

You are given two square binary matrices `img1` and `img2`. You can translate one image by shifting it horizontally and/or vertically.

A translation causes two `1`s to overlap when their relative positions become the same.

Return the **maximum number of `1`s that can overlap** after translating one image.

---

## Approach

Instead of trying every possible translation directly, consider the coordinates of all `1`s in both images.

For every `1` at `(r1, c1)` in `img1` and every `1` at `(r2, c2)` in `img2`, calculate the translation required to align them:

```text
dr = r2 - r1
dc = c2 - c1
```

If multiple pairs produce the same translation `(dr, dc)`, all those pixels can overlap simultaneously using that translation.

Therefore:

1. Store the coordinates of all `1`s in both images.
2. Generate every possible translation between a `1` from `img1` and a `1` from `img2`.
3. Count the frequency of each translation.
4. Return the maximum frequency.

---

## Example

### Input

```text
img1 = [
    [1, 1, 0],
    [0, 1, 0],
    [0, 1, 0]
]

img2 = [
    [0, 0, 0],
    [0, 1, 1],
    [0, 0, 1]
]
```

A suitable translation aligns three `1`s, so the answer is:

```text
3
```

---

## C++ Solution

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();

        vector<pair<int, int>> ones1, ones2;

        // Store coordinates of all 1s
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (img1[i][j] == 1)
                    ones1.push_back({i, j});

                if (img2[i][j] == 1)
                    ones2.push_back({i, j});
            }
        }

        // Count each translation
        map<pair<int, int>, int> count;
        int ans = 0;

        for (auto [r1, c1] : ones1) {
            for (auto [r2, c2] : ones2) {
                int dr = r2 - r1;
                int dc = c2 - c1;

                count[{dr, dc}]++;
                ans = max(ans, count[{dr, dc}]);
            }
        }

        return ans;
    }
};
```

---

## Complexity

Let:

* `n` = size of the matrix
* `k1` = number of `1`s in `img1`
* `k2` = number of `1`s in `img2`

### Time Complexity

```text
O(n² + k1 × k2 × log(k1 × k2))
```

The `n²` term is used to find all `1`s, while the remaining work counts translation vectors using a `map`.

### Space Complexity

```text
O(k1 × k2)
```

in the worst case for the translation map.

---

## Key Insight

The important observation is:

> **Pixels that overlap after the same translation have the same difference in their row and column coordinates.**

So instead of checking every possible shifted matrix, count identical translation vectors and take the largest count.
