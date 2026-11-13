# LeetCode 3420 – Count Non-Decreasing Subarrays After K Operations

## Problem Statement
Given an integer array `nums` and an integer `k`, return the number of subarrays that can be made non-decreasing using at most `k` operations.

In one operation, you can increase an element by 1.

## Approach: Monotonic Deque + Sliding Window

We use a monotonic deque and a sliding window to efficiently calculate the minimum number of operations required to make each subarray non-decreasing.

### Algorithm
1. Traverse the array from right to left.
2. Maintain a monotonic deque to track indices of elements.
3. When a larger element is encountered, update the operation cost for the affected elements.
4. Maintain a sliding window by adjusting the right pointer whenever the operation cost exceeds `k`.
5. Add the number of valid subarrays ending at the current index to the answer.
6. Return the total count.

## Java Solution

```java
import java.util.*;

class Solution {
    public long countNonDecreasingSubarrays(int[] nums, int k) {
        int n = nums.length;
        Deque<Integer> dq = new ArrayDeque<>();

        long cost = 0;
        long ans = 0;
        int j = n - 1;

        for (int i = n - 1; i >= 0; i--) {
            while (!dq.isEmpty() &&
                   nums[dq.peekLast()] < nums[i]) {

                int left = dq.pollLast();
                int right = dq.isEmpty() ? j + 1 : dq.peekLast();

                cost += (long) (right - left) *
                        (nums[i] - nums[left]);
            }

            dq.offerLast(i);

            while (cost > k) {
                cost -= nums[dq.peekFirst()] - nums[j];

                if (dq.peekFirst() == j) {
                    dq.pollFirst();
                }

                j--;
            }

            ans += j - i + 1;
        }

        return ans;
    }
}
```

## Complexity Analysis

| Complexity | Value | Explanation |
|---|---|---|
| Time | O(n) | Each index is inserted and removed from the deque at most once. |
| Space | O(n) | The deque stores indices of array elements. |

## Key Concepts
- Sliding Window
- Monotonic Deque
- Greedy Algorithm
- Two Pointers
- Array Optimization

## Edge Cases
- Array containing a single element.
- Already non-decreasing array.
- Strictly decreasing array.
- `k = 0`.
- Large values of `k`.

## Conclusion
The monotonic deque combined with a sliding window efficiently tracks the operations required to make subarrays non-decreasing. This approach avoids checking every possible subarray individually and achieves linear time complexity.

**LeetCode Problem:** 3420  
**Difficulty:** Hard  
**Language:** Java
