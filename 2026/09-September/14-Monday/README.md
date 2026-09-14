# LeetCode 836 - Rectangle Overlap

## Problem Description

You are given two axis-aligned rectangles represented as arrays:

```text
rec1 = [x1, y1, x2, y2]
rec2 = [x1, y1, x2, y2]
```

where:

* `(x1, y1)` represents the bottom-left corner.
* `(x2, y2)` represents the top-right corner.

Return `true` if the two rectangles overlap with a **positive area**. Otherwise, return `false`.

Rectangles that only touch at their edges or corners are **not** considered overlapping.

---

## Approach

For two rectangles to have a positive-area overlap:

1. Their projections on the **x-axis** must overlap.
2. Their projections on the **y-axis** must overlap.

### Horizontal Overlap

```text
max(rec1[0], rec2[0]) < min(rec1[2], rec2[2])
```

### Vertical Overlap

```text
max(rec1[1], rec2[1]) < min(rec1[3], rec2[3])
```

Both conditions must be true.

The strict `<` comparison is important because if the boundaries are equal, the rectangles only touch and have zero overlapping area.

---

## Algorithm

1. Find the larger of the two left `x` coordinates.
2. Find the smaller of the two right `x` coordinates.
3. Check whether the horizontal intervals overlap.
4. Do the same for the `y` coordinates.
5. Return `true` only if both dimensions overlap.

---

## Complexity

* **Time Complexity:** `O(1)`
* **Space Complexity:** `O(1)`

---

## Solutions

### Python

```python
class Solution:
    def isRectangleOverlap(self, rec1: List[int], rec2: List[int]) -> bool:
        return (
            max(rec1[0], rec2[0]) < min(rec1[2], rec2[2])
            and
            max(rec1[1], rec2[1]) < min(rec1[3], rec2[3])
        )
```

### Java

```java
class Solution {
    public boolean isRectangleOverlap(int[] rec1, int[] rec2) {
        return Math.max(rec1[0], rec2[0]) < Math.min(rec1[2], rec2[2]) &&
               Math.max(rec1[1], rec2[1]) < Math.min(rec1[3], rec3[3]);
    }
}
```

### C++

```cpp
class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        return max(rec1[0], rec2[0]) < min(rec1[2], rec2[2]) &&
               max(rec1[1], rec2[1]) < min(rec1[3], rec2[3]);
    }
};
```

### C#

```csharp
public class Solution
{
    public bool IsRectangleOverlap(int[] rec1, int[] rec2)
    {
        return Math.Max(rec1[0], rec2[0]) < Math.Min(rec1[2], rec2[2]) &&
               Math.Max(rec1[1], rec2[1]) < Math.Min(rec1[3], rec2[3]);
    }
}
```

### C

```c
bool isRectangleOverlap(int* rec1, int rec1Size, int* rec2, int rec2Size) {
    return (rec1[0] < rec2[2] && rec2[0] < rec1[2] &&
            rec1[1] < rec2[3] && rec2[1] < rec1[3]);
}
```

---

## Key Insight

Two rectangles overlap with positive area **only when they overlap on both axes**.

```text
X-axis overlap  &&  Y-axis overlap
            ↓
      Rectangle Overlap
```

If either axis has no overlap, the rectangles do not overlap.
