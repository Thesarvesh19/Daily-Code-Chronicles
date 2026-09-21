# LeetCode 3524 - Find X Value of Array I

## Problem

You are given an integer array `nums` and an integer `k`.

For every possible value `x` from `0` to `k - 1`, count the number of non-empty subarrays whose product modulo `k` is equal to `x`.

Return an array `ans` of size `k`, where:

```text
ans[x] = number of subarrays whose product % k == x
```

---

## Approach

We use Dynamic Programming based on the remainder of the product modulo `k`.

### DP Definition

Let:

```text
dp[r]
```

represent the number of subarrays ending at the previous position whose product has remainder `r` when divided by `k`.

When processing a new number `num`:

```text
mod = num % k
```

There are two possibilities.

### 1. Start a New Subarray

The subarray containing only `num` has:

```text
product % k = num % k
```

So:

```text
newDp[mod]++
```

### 2. Extend an Existing Subarray

If an existing subarray has product remainder `r`, after multiplying by `num`, its new remainder becomes:

```text
(r * mod) % k
```

Therefore:

```text
newDp[(r * mod) % k] += dp[r]
```

After processing the current element, all values in `newDp` are added to the final answer.

---

## Why This Works

Instead of calculating the actual product of every subarray, we only keep its remainder modulo `k`.

For example, if:

```text
k = 3
```

and an existing subarray has:

```text
product % 3 = 2
```

and the next number satisfies:

```text
num % 3 = 2
```

then:

```text
new remainder = (2 * 2) % 3
              = 1
```

Therefore, we only need `k` DP states.

---

## Algorithm

1. Create an answer array of size `k`.
2. Create a DP array of size `k`.
3. Iterate through every number in `nums`.
4. Calculate `num % k`.
5. Create a new DP array.
6. Add the single-element subarray.
7. Extend every previous subarray and calculate its new remainder.
8. Add the new DP values to the answer.
9. Replace `dp` with `newDp`.
10. Return `ans`.

---

## Complexity

Let:

- `n = nums.length`
- `k` = given modulo

### Time Complexity

```text
O(n * k)
```

Since `k` is very small, this is effectively:

```text
O(n)
```

### Space Complexity

```text
O(k)
```

---

# Python

```python
from typing import List

class Solution:
    def resultArray(self, nums: List[int], k: int) -> List[int]:
        ans = [0] * k
        dp = [0] * k

        for num in nums:
            mod = num % k
            new_dp = [0] * k

            # Start a new subarray with only num
            new_dp[mod] += 1

            # Extend previous subarrays
            for r in range(k):
                new_remainder = (r * mod) % k
                new_dp[new_remainder] += dp[r]

            # Add current subarrays to the answer
            for r in range(k):
                ans[r] += new_dp[r]

            dp = new_dp

        return ans
```

---

# Java

```java
class Solution {
    public long[] resultArray(int[] nums, int k) {
        long[] ans = new long[k];
        long[] dp = new long[k];

        for (int num : nums) {
            int mod = num % k;
            long[] newDp = new long[k];

            // Start a new subarray with only num
            newDp[mod]++;

            // Extend previous subarrays
            for (int r = 0; r < k; r++) {
                int newRemainder = (r * mod) % k;
                newDp[newRemainder] += dp[r];
            }

            // Add current subarrays to the answer
            for (int r = 0; r < k; r++) {
                ans[r] += newDp[r];
            }

            dp = newDp;
        }

        return ans;
    }
}
```

---

# C++

```cpp
class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> ans(k, 0);
        vector<long long> dp(k, 0);

        for (int num : nums) {
            int mod = num % k;
            vector<long long> newDp(k, 0);

            // Start a new subarray with only num
            newDp[mod]++;

            // Extend previous subarrays
            for (int r = 0; r < k; r++) {
                int newRemainder = (r * mod) % k;
                newDp[newRemainder] += dp[r];
            }

            // Add current subarrays to the answer
            for (int r = 0; r < k; r++) {
                ans[r] += newDp[r];
            }

            dp = newDp;
        }

        return ans;
    }
};
```

---

# C#

```csharp
public class Solution
{
    public long[] ResultArray(int[] nums, int k)
    {
        long[] ans = new long[k];
        long[] dp = new long[k];

        foreach (int num in nums)
        {
            int mod = num % k;
            long[] newDp = new long[k];

            // Start a new subarray with only num
            newDp[mod]++;

            // Extend previous subarrays
            for (int r = 0; r < k; r++)
            {
                int newRemainder = (r * mod) % k;
                newDp[newRemainder] += dp[r];
            }

            // Add current subarrays to the answer
            for (int r = 0; r < k; r++)
            {
                ans[r] += newDp[r];
            }

            dp = newDp;
        }

        return ans;
    }
}
```

> **Important for C#:** LeetCode 3524 expects `long[]`, not `int[]`, because the number of subarrays can exceed the 32-bit integer range.

---

# C

```c
#include <stdlib.h>

/**
 * Note: The returned array must be malloced,
 * assume caller calls free().
 */
long long* resultArray(
    int* nums,
    int numsSize,
    int k,
    int* returnSize
) {
    long long* ans = (long long*)calloc(k, sizeof(long long));
    long long* dp = (long long*)calloc(k, sizeof(long long));

    for (int i = 0; i < numsSize; i++) {
        int mod = nums[i] % k;

        long long* newDp =
            (long long*)calloc(k, sizeof(long long));

        // Start a new subarray with only nums[i]
        newDp[mod]++;

        // Extend previous subarrays
        for (int r = 0; r < k; r++) {
            int newRemainder = (r * mod) % k;
            newDp[newRemainder] += dp[r];
        }

        // Add current subarrays to the answer
        for (int r = 0; r < k; r++) {
            ans[r] += newDp[r];
        }

        free(dp);
        dp = newDp;
    }

    free(dp);

    *returnSize = k;
    return ans;
}
```

---

# JavaScript

```javascript
/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number[]}
 */
var resultArray = function(nums, k) {
    const ans = new Array(k).fill(0);
    let dp = new Array(k).fill(0);

    for (const num of nums) {
        const mod = num % k;
        const newDp = new Array(k).fill(0);

        // Start a new subarray with only num
        newDp[mod]++;

        // Extend previous subarrays
        for (let r = 0; r < k; r++) {
            const newRemainder = (r * mod) % k;
            newDp[newRemainder] += dp[r];
        }

        // Add current subarrays to the answer
        for (let r = 0; r < k; r++) {
            ans[r] += newDp[r];
        }

        dp = newDp;
    }

    return ans;
};
```

---

# Kotlin

```kotlin
class Solution {
    fun resultArray(nums: IntArray, k: Int): LongArray {
        val ans = LongArray(k)
        var dp = LongArray(k)

        for (num in nums) {
            val mod = num % k
            val newDp = LongArray(k)

            // Start a new subarray with only num
            newDp[mod]++

            // Extend previous subarrays
            for (r in 0 until k) {
                val newRemainder = (r * mod) % k
                newDp[newRemainder] += dp[r]
            }

            // Add current subarrays to the answer
            for (r in 0 until k) {
                ans[r] += newDp[r]
            }

            dp = newDp
        }

        return ans
    }
}
```

---

# Example

### Input

```text
nums = [1, 2, 3, 4, 5]
k = 3
```

### Output

```text
[9, 2, 4]
```

This means:

```text
9 subarrays have product % 3 == 0
2 subarrays have product % 3 == 1
4 subarrays have product % 3 == 2
```

The total number of non-empty subarrays is:

```text
9 + 2 + 4 = 15
```

And:

```text
n * (n + 1) / 2
= 5 * 6 / 2
= 15
```

So every non-empty subarray is counted exactly once.

---

# Key Insight

The most important formula in this problem is:

```text
new remainder = (old remainder * (num % k)) % k
```

We never calculate the actual product of a subarray.

We only track its remainder modulo `k`.

This reduces the state space from potentially `O(n²)` subarrays to only `O(k)` remainder states.

---

# Pattern to Remember

This problem is an example of:

**Dynamic Programming over Modulo States**

Whenever a problem asks for the number of subarrays or subsequences satisfying a condition involving:

```text
value % k
```

consider maintaining:

```text
dp[0 ... k - 1]
```

where each state represents the number of ways to obtain a particular remainder.

---

# Tags

- Array
- Dynamic Programming
- Modular Arithmetic
- Subarrays
- Counting
- Remainder DP
- Product Remainders
```
