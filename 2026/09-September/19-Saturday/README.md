# LeetCode 1401 - Circle and Rectangle Overlapping

## Problem

You are given a circle represented by its center `(xCenter, yCenter)` and radius `radius`.

You are also given an axis-aligned rectangle represented by its bottom-left corner `(x1, y1)` and top-right corner `(x2, y2)`.

Return `true` if the circle and rectangle overlap, otherwise return `false`.

---

## Approach

The key idea is to find the **closest point on the rectangle to the center of the circle**.

If the distance between this closest point and the circle's center is less than or equal to the radius, then the circle and rectangle overlap.

### Step 1: Find the closest X-coordinate

```text
closestX = max(x1, min(xCenter, x2))
```

This keeps `xCenter` inside the rectangle's horizontal range.

### Step 2: Find the closest Y-coordinate

```text
closestY = max(y1, min(yCenter, y2))
```

This keeps `yCenter` inside the rectangle's vertical range.

### Step 3: Calculate the squared distance

```text
dx = xCenter - closestX
dy = yCenter - closestY

distance² = dx² + dy²
```

We compare squared distances instead of calculating the actual distance using a square root.

### Step 4: Check for overlap

If:

```text
distance² <= radius²
```

then the circle overlaps the rectangle.

---

## Example

### Input

```text
radius = 1
xCenter = 0
yCenter = 0
x1 = 1
y1 = -1
x2 = 3
y2 = 1
```

### Closest Point

```text
closestX = 1
closestY = 0
```

### Distance

```text
dx = 0 - 1 = -1
dy = 0 - 0 = 0

distance² = (-1)² + 0²
           = 1
```

Since:

```text
1 <= 1²
```

the circle overlaps the rectangle.

### Output

```text
true
```

---

## Java Solution

```java
class Solution {
    public boolean checkOverlap(int radius, int xCenter, int yCenter,
                                int x1, int y1, int x2, int y2) {

        // Find the closest point on the rectangle to the circle's center
        int closestX = Math.max(x1, Math.min(xCenter, x2));
        int closestY = Math.max(y1, Math.min(yCenter, y2));

        // Calculate squared distance
        int dx = xCenter - closestX;
        int dy = yCenter - closestY;

        return dx * dx + dy * dy <= radius * radius;
    }
}
```

---

## C++ Solution

```cpp
class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter,
                      int x1, int y1, int x2, int y2) {

        // Find the closest point on the rectangle to the circle's center
        int closestX = max(x1, min(xCenter, x2));
        int closestY = max(y1, min(yCenter, y2));

        // Calculate squared distance
        int dx = xCenter - closestX;
        int dy = yCenter - closestY;

        return dx * dx + dy * dy <= radius * radius;
    }
};
```

---

## Python Solution

```python
class Solution:
    def checkOverlap(self, radius: int, xCenter: int, yCenter: int,
                     x1: int, y1: int, x2: int, y2: int) -> bool:

        # Find the closest point on the rectangle to the circle's center
        closest_x = max(x1, min(xCenter, x2))
        closest_y = max(y1, min(yCenter, y2))

        # Calculate squared distance
        dx = xCenter - closest_x
        dy = yCenter - closest_y

        return dx * dx + dy * dy <= radius * radius
```

---

## Complexity Analysis

Let `n` represent the input size.

There is no iteration or recursion in the solution. Only a fixed number of arithmetic operations are performed.

### Time Complexity

```text
O(1)
```

### Space Complexity

```text
O(1)
```

---

## Why This Works

The closest point on an axis-aligned rectangle to any given point can be obtained independently for the X and Y coordinates.

For the X-coordinate:

- If `xCenter < x1`, the closest X-coordinate is `x1`.
- If `xCenter` is between `x1` and `x2`, the closest X-coordinate is `xCenter`.
- If `xCenter > x2`, the closest X-coordinate is `x2`.

The same logic applies to the Y-coordinate.

Therefore, `(closestX, closestY)` is guaranteed to be the point on the rectangle with the minimum Euclidean distance from the circle's center.

If that minimum distance is at most the circle's radius, the two shapes overlap.

---

## Key Concept

**Point-to-Rectangle Distance**

```text
closestX = max(x1, min(xCenter, x2))
closestY = max(y1, min(yCenter, y2))
```

Then:

```text
distance² = (xCenter - closestX)²
          + (yCenter - closestY)²
```

Finally:

```text
distance² <= radius²
```

means the circle and rectangle overlap.

---

## Tags

- Geometry
- Math
- Circle
- Rectangle
- Distance
- Computational Geometry

---

## LeetCode

**Problem:** 1401. Circle and Rectangle Overlapping

**Difficulty:** Medium
