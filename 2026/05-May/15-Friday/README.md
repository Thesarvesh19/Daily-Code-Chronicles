# 153. Find Minimum in Rotated Sorted Array

## Problem Statement
Given a sorted array of unique integers that has been rotated between `1` and `n` times, return the minimum element of this array.

You must write an algorithm that runs in **O(log n)** time.

### Example 1
Input:
```txt
nums = [3,4,5,1,2]
```

Output:
```txt
1
```

### Example 2
Input:
```txt
nums = [4,5,6,7,0,1,2]
```

Output:
```txt
0
```

### Example 3
Input:
```txt
nums = [11,13,15,17]
```

Output:
```txt
11
```

---

## Approach: Binary Search

Since the array was originally sorted and then rotated, we can use **Binary Search** to find the minimum element efficiently.

- Calculate middle index.
- If `nums[mid] > nums[right]`, minimum lies in the right half.
- Otherwise, minimum lies in the left half including `mid`.
- Continue until `left == right`.

This gives an optimized solution with logarithmic complexity.

---

## Algorithm
1. Initialize `left = 0` and `right = n - 1`
2. Repeat while `left < right`
   - Find `mid`
   - If `nums[mid] > nums[right]`
     - Move left pointer to `mid + 1`
   - Else
     - Move right pointer to `mid`
3. Return `nums[left]`

---

## Complexity Analysis

- **Time Complexity:** `O(log n)`
- **Space Complexity:** `O(1)`

