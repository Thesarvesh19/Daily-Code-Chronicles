# LeetCode 1658 - Minimum Operations to Reduce X to Zero

## Problem

You are given an integer array `nums` and an integer `x`.

In one operation, you can remove the leftmost or rightmost element from the array and subtract its value from `x`.

Return the **minimum number of operations** to reduce `x` to exactly `0`.

If it is impossible, return `-1`.

---

## Example 1

### Input

```text
nums = [1,1,4,2,3]
x = 5
```

### Output

```text
2
```

### Explanation

Remove `3` from the right:

```text
x = 5 - 3 = 2
```

Then remove `2` from the right:

```text
x = 2 - 2 = 0
```

Therefore, the minimum number of operations is `2`.

---

## Example 2

### Input

```text
nums = [5,6,7,8,9]
x = 4
```

### Output

```text
-1
```

### Explanation

There is no way to remove elements from the two ends such that their sum is exactly `4`.

---

## Example 3

### Input

```text
nums = [3,2,20,1,1,3]
x = 10
```

### Output

```text
5
```

---

## Approach

A direct approach would try removing elements from both ends, but that can lead to many combinations.

Instead, we can transform the problem.

Let:

```text
total = sum(nums)
```

Suppose the elements removed from the left and right have a total sum of `x`.

The elements that remain in the middle therefore have a sum of:

```text
total - x
```

So instead of finding the minimum number of elements to remove, we can find the **longest contiguous subarray whose sum is `total - x`**.

Then:

```text
minimum operations = n - longest subarray length
```

where `n` is the length of the array.

---

## Why Does This Work?

Consider:

```text
nums = [1,1,4,2,3]
x = 5
```

The total sum is:

```text
1 + 1 + 4 + 2 + 3 = 11
```

Therefore, the target sum for the remaining subarray is:

```text
11 - 5 = 6
```

We need to find the longest contiguous subarray with sum `6`.

The subarray:

```text
[1,1,4]
```

has sum:

```text
1 + 1 + 4 = 6
```

Its length is `3`.

The original array has `5` elements, so:

```text
operations = 5 - 3
           = 2
```

Therefore, the answer is:

```text
2
```

---

## Sliding Window

All elements in `nums` are positive.

Because of this, we can use the **sliding window / two-pointer technique**.

### Steps

1. Calculate the total sum of the array.
2. Calculate:
   ```text
   target = total - x
   ```
3. Find the longest subarray with sum equal to `target`.
4. Use a sliding window:
   - Expand the right pointer.
   - If the current sum becomes greater than `target`, move the left pointer.
   - Whenever the current sum equals `target`, update the maximum length.
5. Return:
   ```text
   n - maxLength
   ```
6. If no such subarray exists, return `-1`.

---

## Special Case

If:

```text
target = 0
```

then:

```text
total - x = 0
```

which means:

```text
total = x
```

Therefore, we need to remove every element.

The answer is:

```text
n
```

---

## Java Solution

```java
class Solution {
    public int minOperations(int[] nums, int x) {
        int total = 0;

        for (int num : nums) {
            total += num;
        }

        int target = total - x;

        // We need to remove the entire array
        if (target == 0) {
            return nums.length;
        }

        int left = 0;
        int currentSum = 0;
        int maxLen = -1;

        for (int right = 0; right < nums.length; right++) {
            currentSum += nums[right];

            while (left <= right && currentSum > target) {
                currentSum -= nums[left];
                left++;
            }

            if (currentSum == target) {
                maxLen = Math.max(maxLen, right - left + 1);
            }
        }

        return maxLen == -1 ? -1 : nums.length - maxLen;
    }
}
```

---

## Dry Run

Consider:

```text
nums = [1,1,4,2,3]
x = 5
```

### Step 1: Calculate total

```text
total = 1 + 1 + 4 + 2 + 3
      = 11
```

### Step 2: Calculate target

```text
target = total - x
       = 11 - 5
       = 6
```

Now find the longest subarray with sum `6`.

### Sliding Window

Start with:

```text
left = 0
currentSum = 0
maxLen = -1
```

Add elements one by one:

```text
[1]
sum = 1
```

```text
[1,1]
sum = 2
```

```text
[1,1,4]
sum = 6
```

We found the target.

Length:

```text
3
```

So:

```text
maxLen = 3
```

Add `2`:

```text
sum = 8
```

Since:

```text
8 > 6
```

remove elements from the left until the sum is at most `6`.

Eventually:

```text
[4,2]
sum = 6
```

Length:

```text
2
```

The maximum length remains `3`.

Finally:

```text
answer = n - maxLen
       = 5 - 3
       = 2
```

---

## Complexity Analysis

Let `n` be the number of elements in `nums`.

### Time Complexity

```text
O(n)
```

Each element is added to the sliding window once and removed at most once.

### Space Complexity

```text
O(1)
```

Only a few variables are used.

---

## Important Insight

The key transformation is:

```text
Remove elements with sum x
```

becomes:

```text
Keep the longest subarray with sum total - x
```

Therefore:

```text
answer = n - longestSubarray
```

This converts the problem into a standard **longest subarray with a given sum** problem.

---

## Tags

- Array
- Sliding Window
- Two Pointers
- Prefix Sum
- Greedy
- Medium

---

## LeetCode

**Problem:** 1658 - Minimum Operations to Reduce X to Zero

**Difficulty:** Medium

**Language:** Java
