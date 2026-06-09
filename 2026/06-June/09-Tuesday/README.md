# LeetCode 3689 - Maximum Total Subarray Value I

## Problem Statement

Given an integer array `nums` and an integer `k`, find the maximum total value obtainable by selecting exactly `k` subarrays.

The value of a subarray is defined as:

```text
max(subarray) - min(subarray)
```

Since the same subarray can be chosen multiple times and overlapping is allowed, determine the maximum possible total value.

---

## Key Observation

The maximum value of any subarray is achieved when the subarray contains both:

* The maximum element of the array
* The minimum element of the array

Therefore:

```text
Maximum Subarray Value = max(nums) - min(nums)
```

Since the same subarray may be selected repeatedly:

```text
Answer = (max(nums) - min(nums)) × k
```

---

## Algorithm

1. Find the minimum element in the array.
2. Find the maximum element in the array.
3. Compute their difference.
4. Multiply the difference by `k`.
5. Return the result.

---

## Complexity Analysis

| Complexity | Value |
| ---------- | ----- |
| Time       | O(n)  |
| Space      | O(1)  |

---

## C++ Solution

```cpp
class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        long long mn = *min_element(nums.begin(), nums.end());
        long long mx = *max_element(nums.begin(), nums.end());

        return (mx - mn) * 1LL * k;
    }
};
```

---

## Java Solution

```java
class Solution {
    public long maxTotalValue(int[] nums, int k) {
        long mn = nums[0];
        long mx = nums[0];

        for (int num : nums) {
            mn = Math.min(mn, num);
            mx = Math.max(mx, num);
        }

        return (mx - mn) * k;
    }
}
```

---

## Python Solution

```python
class Solution:
    def maxTotalValue(self, nums: List[int], k: int) -> int:
        return (max(nums) - min(nums)) * k
```

---

## Example

### Input

```text
nums = [1, 5, 2, 8]
k = 3
```

### Calculation

```text
max(nums) = 8
min(nums) = 1

Maximum Subarray Value = 8 - 1 = 7
Total Value = 7 × 3 = 21
```

### Output

```text
21
```

---

## Tags

* Array
* Greedy
* Math
* Simulation
