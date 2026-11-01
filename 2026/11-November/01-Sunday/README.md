
# 453. Minimum Moves to Equal Array Elements

## Problem
Given an integer array `nums` of size `n`, return the minimum number of moves required to make all array elements equal.

In one move, you can increment `n - 1` elements of the array by `1`.

## Approach: Mathematical Optimization

Instead of incrementing `n - 1` elements, we can think of each operation as decrementing one element by `1`.

To make all elements equal with the minimum number of moves, we need to make every element equal to the minimum element in the array.

**Formula:**

```text
Minimum Moves = Sum(nums) - (n * Minimum(nums))
```

Where:
- `Sum(nums)` is the sum of all array elements.
- `n` is the length of the array.
- `Minimum(nums)` is the smallest element in the array.

## Solutions

### C++

```cpp
class Solution {
public:
    int minMoves(vector<int>& nums) {
        int minVal = *min_element(nums.begin(), nums.end());
        int sum = accumulate(nums.begin(), nums.end(), 0);
        return sum - (nums.size() * minVal);
    }
};
```

### Java

```java
class Solution {
    public int minMoves(int[] nums) {
        int minVal = Integer.MAX_VALUE;
        int sum = 0;

        for (int num : nums) {
            minVal = Math.min(minVal, num);
            sum += num;
        }

        return sum - (nums.length * minVal);
    }
}
```

### C

```c
int minMoves(int* nums, int numsSize) {
    int minVal = nums[0];
    int sum = 0;

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] < minVal) {
            minVal = nums[i];
        }
        sum += nums[i];
    }

    return sum - (numsSize * minVal);
}
```

### C#

```csharp
public class Solution {
    public int MinMoves(int[] nums) {
        int minVal = int.MaxValue;
        int sum = 0;

        foreach (int num in nums) {
            minVal = Math.Min(minVal, num);
            sum += num;
        }

        return sum - (nums.Length * minVal);
    }
}
```

### Kotlin

```kotlin
class Solution {
    fun minMoves(nums: IntArray): Int {
        val minVal = nums.minOrNull()!!
        val sum = nums.sum()

        return sum - nums.size * minVal
    }
}
```

### JavaScript

```javascript
var minMoves = function(nums) {
    const minVal = Math.min(...nums);
    const sum = nums.reduce((a, b) => a + b, 0);

    return sum - nums.length * minVal;
};
```

### TypeScript

```typescript
function minMoves(nums: number[]): number {
    const minVal = Math.min(...nums);
    const sum = nums.reduce((a, b) => a + b, 0);

    return sum - nums.length * minVal;
}
```

## Example

**Input:**
```text
nums = [1, 2, 3]
```

**Calculation:**
```text
Minimum element = 1
Sum = 1 + 2 + 3 = 6
Array length = 3

Minimum Moves = 6 - (3 * 1)
              = 3
```

**Output:**
```text
3
```

## Complexity Analysis

| Complexity | Value | Explanation |
|---|---|---|
| Time Complexity | O(n) | Finding the minimum and calculating the sum requires one traversal. |
| Space Complexity | O(1) | Only a constant amount of extra space is used. |

## Key Takeaway

The problem can be optimized using a simple mathematical observation. Instead of simulating individual operations, we calculate the difference between the total sum and the sum obtained when every element equals the minimum element.

This approach provides an optimal **O(n) time complexity and O(1) auxiliary space complexity**.

---

