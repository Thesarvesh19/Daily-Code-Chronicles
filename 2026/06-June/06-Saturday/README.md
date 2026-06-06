# 2574. Left and Right Sum Differences

## Problem

Given a 0-indexed integer array `nums`, find an integer array `answer` where:

- answer[i] = |leftSum[i] - rightSum[i]|
- leftSum[i] is the sum of elements before index i.
- rightSum[i] is the sum of elements after index i.

Return the resulting array.

---

## Example

Input:

nums = [10,4,8,3]

Output:

[15,1,11,22]

Explanation:

leftSum  = [0,10,14,22]

rightSum = [15,11,3,0]

answer   = [15,1,11,22]

---

## Approach

1. Compute the total sum of the array.
2. Maintain a running `leftSum`.
3. For every index:
   - Remove current element from total to obtain rightSum.
   - Compute:

     abs(leftSum - rightSum)

   - Update leftSum.

This avoids building separate prefix and suffix arrays.

---

## Algorithm

1. Calculate total sum.
2. Initialize leftSum = 0.
3. Traverse the array:
   - total -= nums[i]
   - answer[i] = abs(leftSum - total)
   - leftSum += nums[i]
4. Return answer.

---

## Complexity Analysis

### Time Complexity

O(n)

Single traversal after calculating total sum.

### Space Complexity

O(1)

Ignoring the output array.

---


## Key Idea

At any index:

rightSum = totalSum - currentElement - leftSum

Instead of storing prefix and suffix arrays, we keep only:

- totalSum
- leftSum

which reduces auxiliary space to O(1).
