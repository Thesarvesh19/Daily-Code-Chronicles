# LeetCode 1344 - Angle Between Hands of a Clock

## Problem Statement

Given two integers `hour` and `minutes`, return the smaller angle (in degrees) formed between the hour and minute hands of an analog clock.

The answer is accepted if it is within `10^-5` of the actual answer.

---

## Examples

### Example 1

**Input**
```text
hour = 12, minutes = 30
```

**Output**
```text
165
```

### Example 2

**Input**
```text
hour = 3, minutes = 30
```

**Output**
```text
75
```

### Example 3

**Input**
```text
hour = 3, minutes = 15
```

**Output**
```text
7.5
```

---

## Intuition

An analog clock contains two moving hands:

1. **Hour Hand**
2. **Minute Hand**

To determine the angle between them, we first calculate the angle of each hand from the 12 o'clock position.

### Minute Hand Movement

The minute hand completes one full rotation:

```text
360° in 60 minutes
```

Therefore:

```text
1 minute = 6°
```

So:

```text
Minute Hand Angle = minutes × 6
```

### Hour Hand Movement

The hour hand completes one full rotation:

```text
360° in 12 hours
```

Therefore:

```text
1 hour = 30°
```

However, the hour hand continuously moves as minutes pass.

For every minute:

```text
30° / 60 = 0.5°
```

So:

```text
Hour Hand Angle = (hour % 12) × 30 + minutes × 0.5
```

After finding both angles, we compute their absolute difference.

Since two angles are formed between the hands, we return the smaller one.

---

## Approach

### Step 1

Calculate the hour hand angle.

```text
hourAngle = (hour % 12) × 30 + minutes × 0.5
```

### Step 2

Calculate the minute hand angle.

```text
minuteAngle = minutes × 6
```

### Step 3

Find the absolute difference.

```text
diff = |hourAngle - minuteAngle|
```

### Step 4

Return the smaller angle.

```text
min(diff, 360 - diff)
```

---

## Dry Run

### Input

```text
hour = 3
minutes = 15
```

### Hour Hand

```text
(3 × 30) + (15 × 0.5)
= 90 + 7.5
= 97.5°
```

### Minute Hand

```text
15 × 6
= 90°
```

### Difference

```text
|97.5 - 90|
= 7.5°
```

### Smaller Angle

```text
min(7.5, 360 - 7.5)
= 7.5°
```

### Output

```text
7.5
```

---

# C++ Solution

```cpp
class Solution {
public:
    double angleClock(int hour, int minutes) {
        double hourAngle = (hour % 12) * 30 + minutes * 0.5;
        double minuteAngle = minutes * 6;

        double diff = abs(hourAngle - minuteAngle);

        return min(diff, 360.0 - diff);
    }
};
```

---

# Java Solution

```java
class Solution {
    public double angleClock(int hour, int minutes) {
        double hourAngle = (hour % 12) * 30 + minutes * 0.5;
        double minuteAngle = minutes * 6;

        double diff = Math.abs(hourAngle - minuteAngle);

        return Math.min(diff, 360.0 - diff);
    }
}
```

---

# Python Solution

```python
class Solution:
    def angleClock(self, hour: int, minutes: int) -> float:
        hour_angle = (hour % 12) * 30 + minutes * 0.5
        minute_angle = minutes * 6

        diff = abs(hour_angle - minute_angle)

        return min(diff, 360 - diff)
```

---

# C Solution

```c
double angleClock(int hour, int minutes) {
    double hourAngle = (hour % 12) * 30.0 + minutes * 0.5;
    double minuteAngle = minutes * 6.0;

    double diff = fabs(hourAngle - minuteAngle);

    return fmin(diff, 360.0 - diff);
}
```

---

# C# Solution

```csharp
public class Solution {
    public double AngleClock(int hour, int minutes) {
        double hourAngle = (hour % 12) * 30.0 + minutes * 0.5;
        double minuteAngle = minutes * 6.0;

        double diff = Math.Abs(hourAngle - minuteAngle);

        return Math.Min(diff, 360.0 - diff);
    }
}
```

---

# JavaScript Solution

```javascript
var angleClock = function(hour, minutes) {
    const hourAngle = (hour % 12) * 30 + minutes * 0.5;
    const minuteAngle = minutes * 6;

    const diff = Math.abs(hourAngle - minuteAngle);

    return Math.min(diff, 360 - diff);
};
```

---

# Kotlin Solution

```kotlin
class Solution {
    fun angleClock(hour: Int, minutes: Int): Double {
        val hourAngle = (hour % 12) * 30.0 + minutes * 0.5
        val minuteAngle = minutes * 6.0

        val diff = kotlin.math.abs(hourAngle - minuteAngle)

        return minOf(diff, 360.0 - diff)
    }
}
```

---

# Go Solution

```go
import "math"

func angleClock(hour int, minutes int) float64 {
    hourAngle := float64(hour%12)*30.0 + float64(minutes)*0.5
    minuteAngle := float64(minutes) * 6.0

    diff := math.Abs(hourAngle - minuteAngle)

    return math.Min(diff, 360.0-diff)
}
---

# PHP Solution

```php
class Solution {

    /**
     * @param Integer $hour
     * @param Integer $minutes
     * @return Float
     */
    function angleClock($hour, $minutes) {
        $hourAngle = ($hour % 12) * 30 + $minutes * 0.5;
        $minuteAngle = $minutes * 6;

        $diff = abs($hourAngle - $minuteAngle);

        return min($diff, 360 - $diff);
    }
}
---

## Complexity Analysis

### Time Complexity

```text
O(1)
```

Only a few mathematical calculations are performed.

### Space Complexity

```text
O(1)
```

No extra data structures are used.

---

## Key Observations

- Minute hand moves **6° per minute**.
- Hour hand moves **30° per hour**.
- Hour hand additionally moves **0.5° per minute**.
- Calculate both hand angles independently.
- Use absolute difference to get the angle.
- Return the smaller angle using:

```text
min(diff, 360 - diff)
```

This yields an optimal constant-time and constant-space solution.
````
