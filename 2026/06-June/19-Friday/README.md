# 1732. Find the Highest Altitude

## Easy

### Problem Statement

There is a biker going on a road trip. The trip consists of `n + 1` points at different altitudes.

You are given an integer array `gain` where:

* `gain[i]` is the net gain in altitude between points `i` and `i + 1`.
* The biker starts the trip at altitude `0`.

Return the **highest altitude** reached during the trip.

---

## Example 1

### Input

```text
gain = [-5,1,5,0,-7]
```

### Output

```text
1
```

### Explanation

Altitude changes:

```text
Start: 0
0 + (-5) = -5
-5 + 1 = -4
-4 + 5 = 1
1 + 0 = 1
1 + (-7) = -6
```

The highest altitude reached is:

```text
max(0, -5, -4, 1, 1, -6) = 1
```

---

## Example 2

### Input

```text
gain = [-4,-3,-2,-1,4,3,2]
```

### Output

```text
0
```

### Explanation

The biker never reaches an altitude higher than the starting altitude.

---

## Approach

The biker starts at altitude `0`.

For every value in `gain`:

1. Add the gain to the current altitude.
2. Update the highest altitude seen so far.
3. Return the maximum altitude after processing all gains.

This is a simple prefix-sum problem.

---

## Algorithm

1. Initialize:

   * `altitude = 0`
   * `highest = 0`
2. Traverse the `gain` array.
3. Update altitude:

   ```text
   altitude += gain[i]
   ```
4. Update highest altitude:

   ```text
   highest = max(highest, altitude)
   ```
5. Return `highest`.

---

## Dry Run

### Input

```text
gain = [-5,1,5,0,-7]
```

| Gain  | Current Altitude | Highest Altitude |
| ----- | ---------------- | ---------------- |
| Start | 0                | 0                |
| -5    | -5               | 0                |
| 1     | -4               | 0                |
| 5     | 1                | 1                |
| 0     | 1                | 1                |
| -7    | -6               | 1                |

### Result

```text
1
```

---

## Python

```python
class Solution:
    def largestAltitude(self, gain: List[int]) -> int:
        altitude = 0
        highest = 0

        for g in gain:
            altitude += g
            highest = max(highest, altitude)

        return highest
```

---

## Java

```java
class Solution {
    public int largestAltitude(int[] gain) {
        int altitude = 0;
        int highest = 0;

        for (int g : gain) {
            altitude += g;
            highest = Math.max(highest, altitude);
        }

        return highest;
    }
}
```

---

## C++

```cpp
class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int altitude = 0;
        int highest = 0;

        for (int g : gain) {
            altitude += g;
            highest = max(highest, altitude);
        }

        return highest;
    }
};
```

---

## C

```c
int largestAltitude(int* gain, int gainSize) {
    int altitude = 0;
    int highest = 0;

    for (int i = 0; i < gainSize; i++) {
        altitude += gain[i];

        if (altitude > highest) {
            highest = altitude;
        }
    }

    return highest;
}
```

---

## C#

```csharp
public class Solution {
    public int LargestAltitude(int[] gain) {
        int altitude = 0;
        int highest = 0;

        foreach (int g in gain) {
            altitude += g;
            highest = Math.Max(highest, altitude);
        }

        return highest;
    }
}
```

---

## JavaScript

```javascript
var largestAltitude = function(gain) {
    let altitude = 0;
    let highest = 0;

    for (const g of gain) {
        altitude += g;
        highest = Math.max(highest, altitude);
    }

    return highest;
};
```

---

## Go

```go
func largestAltitude(gain []int) int {
    altitude, highest := 0, 0

    for _, g := range gain {
        altitude += g

        if altitude > highest {
            highest = altitude
        }
    }

    return highest
}
```

---

## Kotlin

```kotlin
class Solution {
    fun largestAltitude(gain: IntArray): Int {
        var altitude = 0
        var highest = 0

        for (g in gain) {
            altitude += g
            highest = maxOf(highest, altitude)
        }

        return highest
    }
}
```

---

## Complexity Analysis

### Time Complexity

```text
O(n)
```

We traverse the array exactly once.

### Space Complexity

```text
O(1)
```

Only two variables (`altitude` and `highest`) are used regardless of input size.

---

## Key Takeaways

* Uses the Prefix Sum concept.
* Tracks cumulative altitude changes.
* Updates the maximum altitude during traversal.
* Optimal solution with O(n) time and O(1) space complexity.
