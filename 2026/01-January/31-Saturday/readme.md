# Find Smallest Letter Greater Than Target

This problem finds the smallest character in a sorted list that is strictly greater than a given target character.

If no such character exists, the search wraps around and returns the first character in the list.

---

## Problem Summary

- You are given a sorted array of lowercase letters
- You are given a target letter
- Find the smallest letter that is lexicographically greater than the target
- If none exists, return the first letter of the array

---

## Example

Input:
letters = ["c", "f", "j"]  
target = "c"

Output:
"f"

---

## Approach Used

- Since the array is already sorted, **Binary Search** is used
- This makes the solution fast and efficient
- Time Complexity: **O(log n)**
- Space Complexity: **O(1)**

---

## Python Logic (Simple Explanation)

Below is a simple Python implementation using binary search:

```python
def nextGreatestLetter(letters, target):
    left, right = 0, len(letters) - 1
    answer = letters[0]   # default wrap-around answer

    while left <= right:
        mid = (left + right) // 2

        if letters[mid] > target:
            answer = letters[mid]
            right = mid - 1
        else:
            left = mid + 1

    return answer
