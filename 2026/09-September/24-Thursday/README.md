# LeetCode 3550 - Smallest Index With Digit Sum Equal to Index

## Problem

You are given a **0-indexed integer array `nums`**.

Return the **smallest index `i`** such that the sum of the digits of `nums[i]` is equal to `i`.

If no such index exists, return `-1`.

### Example

**Input:**
```text
nums = [1, 3, 2, 4]
```

**Output:**
```text
2
```

**Explanation:**

- Index `0`: `1` → digit sum = `1` ≠ `0`
- Index `1`: `3` → digit sum = `3` ≠ `1`
- Index `2`: `2` → digit sum = `2` = `2`

Therefore, the smallest valid index is `2`.

---

## Approach

We iterate through the array from left to right.

For every index `i`:

1. Take `nums[i]`.
2. Calculate the sum of its digits.
3. Compare the digit sum with the current index `i`.
4. If they are equal, return `i`.
5. If no index satisfies the condition, return `-1`.

Because we traverse from left to right, the first valid index is automatically the **smallest index**.

---

## How to Calculate Digit Sum

For a number `num`, repeatedly:

- Take the last digit using `num % 10`.
- Add it to the digit sum.
- Remove the last digit using `num /= 10`.

For example:

```text
num = 123

123 % 10 = 3
123 / 10 = 12

12 % 10 = 2
12 / 10 = 1

1 % 10 = 1
1 / 10 = 0

Digit Sum = 3 + 2 + 1 = 6
```

---

## C++ Solution

```cpp
class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            int sum = 0;

            while (num > 0) {
                sum += num % 10;
                num /= 10;
            }

            if (sum == i) {
                return i;
            }
        }

        return -1;
    }
};
```

---

## Python Solution

```python
class Solution:
    def smallestIndex(self, nums: List[int]) -> int:
        for i, num in enumerate(nums):
            digit_sum = sum(map(int, str(num)))

            if digit_sum == i:
                return i

        return -1
```

---

## Java Solution

```java
class Solution {
    public int smallestIndex(int[] nums) {
        for (int i = 0; i < nums.length; i++) {
            int num = nums[i];
            int sum = 0;

            while (num > 0) {
                sum += num % 10;
                num /= 10;
            }

            if (sum == i) {
                return i;
            }
        }

        return -1;
    }
}
```

---

## C Solution

```c
int smallestIndex(int* nums, int numsSize) {
    for (int i = 0; i < numsSize; i++) {
        int num = nums[i];
        int sum = 0;

        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }

        if (sum == i) {
            return i;
        }
    }

    return -1;
}
```

---

## C# Solution

```csharp
public class Solution {
    public int SmallestIndex(int[] nums) {
        for (int i = 0; i < nums.Length; i++) {
            int num = nums[i];
            int sum = 0;

            while (num > 0) {
                sum += num % 10;
                num /= 10;
            }

            if (sum == i) {
                return i;
            }
        }

        return -1;
    }
}
```

---

## Complexity Analysis

Let:

- `n` = number of elements in the array
- `d` = maximum number of digits in an element

### Time Complexity

```text
O(n × d)
```

For every element, we may process all of its digits.

### Space Complexity

```text
O(1)
```

Only a few integer variables are used.

---

## Key Takeaway

The main idea is simple:

```text
For every index i:
    Calculate digit sum of nums[i]
    If digit sum == i:
        return i

Return -1
```

Since the array is traversed from the beginning, the first matching index is guaranteed to be the smallest valid index.
