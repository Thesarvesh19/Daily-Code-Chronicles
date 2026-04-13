# 1848. Minimum Distance to the Target Element

## Problem Statement

Given an integer array `nums` (0-indexed) and two integers `target` and `start`,  
find an index `i` such that:

- `nums[i] == target`
- The value of `|i - start|` is minimized 

Return the minimum value of `|i - start|`.

Note: `|x|` denotes the absolute value of `x`.

It is guaranteed that `target` exists in the array.

---

## Examples

### Example 1
Input:
nums = [1,2,3,4,5], target = 5, start = 3  
Output:
1  

Explanation:  
The only index with value `5` is `i = 4`  
Distance = |4 - 3| = 1

---

### Example 2
Input:
nums = [1], target = 1, start = 0  
Output:
0  

---

### Example 3
Input:
nums = [1,1,1,1,1,1,1,1,1,1], target = 1, start = 0  
Output:
0  

---

## Constraints

- 1 <= nums.length <= 1000  
- 1 <= nums[i] <= 10^4  
- 0 <= start < nums.length  
- target is guaranteed to exist in nums  

---

## Approach

Brute Force (Optimal for this problem)

- Traverse the array
- For every index `i` where `nums[i] == target`
- Compute distance `abs(i - start)`
- Keep track of the minimum distance

---

## Algorithm

1. Initialize `ans = infinity`
2. Loop through the array:
   - If `nums[i] == target`:
     - Update `ans = min(ans, abs(i - start))`
3. Return `ans`

---

## Complexity Analysis

- Time Complexity: O(n)
- Space Complexity: O(1)

---

## Optimized Idea (Early Exit)

Instead of scanning the entire array:
- Start from index `start`
- Expand towards left and right
- Return immediately when target is found

---

## Edge Cases

- Array of size 1
- All elements equal to target
- Target present at start index
- Multiple occurrences of target

---

## Key Insight

The problem reduces to minimizing the absolute difference between indices.  
Checking all occurrences of the target guarantees correctness.
