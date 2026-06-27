# LeetCode 3020: Find the Maximum Number of Elements in Subset

## 📝 Problem Description

You are given an array of positive integers `nums`.

You need to select a subset of `nums` which satisfies the following condition:
* You can place the selected elements in a **0-indexed** array such that it follows a symmetric pattern of squaring numbers:
  $$[x, x^2, x^4, \dots, x^k, \dots, x^4, x^2, x]$$
* In other words, the array grows exponentially by squaring the previous element up to a peak element $x^k$, and then symmetrically decreases by taking square roots back down to $x$.

Return *the **maximum number of elements** in a subset that satisfies these conditions.*

### Examples

**Example 1:**
> **Input:** `nums = [5,4,1,2,2]`  
> **Output:** `3`  
> **Explanation:** We can select the subset `[2,4,2]` which can be arranged as `[2,4,2]` (where $x=2, x^2=4$). The maximum length is 3.

**Example 2:**
> **Input:** `nums = [1,3,2,4]`  
> **Output:** `1`  
> **Explanation:** The maximum length we can achieve is 1 (e.g., choosing `[3]` or `[2]`).

### Constraints
* $2 \le \text{nums.length} \le 10^5$
* $1 \le \text{nums}[i] \le 10^9$

---

## 💡 Intuition & Approach

1. **Symmetric Frequencies:** For any valid sequence based on $x > 1$, every element below the peak ($x, x^2, x^4 \dots$) must appear **at least twice** (once for the left side, once for the right side). The peak element ($x^k$) must appear **at least once**.
2. **Rapid Growth:** Because $x$ is squared at every step ($x \to x^2 \to x^4 \to x^8 \dots$), the chain grows extremely fast. Even for the smallest base $x = 2$, it exceeds the constraint limit of $10^9$ in just 5 steps. Thus, a simulation approach is optimal.
3. **The Special Case of `1`:** Since $1^2 = 1$, any number of ones can theoretically chain together. However, a valid subset pattern must have an odd length with a single peak. Therefore, if `1` is present, the maximum sequence we can form purely out of ones is the **largest odd count of 1s** available in the array.

### Algorithm
1. Count the frequency of all numbers using a Hash Map (Frequency Map).
2. Initialize `ans` with the maximum possible odd length of `1`s (if `1` exists in the array, otherwise `1`).
3. Iterate through each unique number in the map (skipping `1`):
   * Keep squaring the number (`x = x * x`) as long as the frequency of the current `x` is $\ge 2$. Add `2` to the temporary length for each successful step.
   * When the loop breaks, check if the current `x` exists at least once. If it does, it can act as our peak element (`length += 1`). If it doesn't, the last element we counted twice must act as our peak instead (`length -= 1`).
   * Update `ans = max(ans, length)`.
4. Return `ans`.

---

## 🛠️ Implementation

### Python 3

```python
from collections import Counter

class Solution:
    def maximumLength(self, nums: list[int]) -> int:
        count = Counter(nums)
        
        # Handle edge case for 1: max odd number of 1s
        ans = count[1] - (count[1] % 2 == 0) if count[1] > 0 else 1
        
        for num in count:
            if num == 1:
                continue
                
            length = 0
            x = num
            
            while count[x] >= 2:
                length += 2
                x *= x
            
            if count[x] >= 1:
                length += 1
            else:
                length -= 1
                
            ans = max(ans, length)
            
        return ans
