# Count Binary Substrings

## Problem Statement

Given a string `s` containing only characters '0' and '1', return the number of non-empty substrings that have:

- The same number of consecutive 0s and 1s
- All the 0s and all the 1s in the substring are grouped consecutively

## Example

Input:
s = "00110011"

Output:
6

Explanation:
The valid substrings are:
"0011", "01", "1100", "10", "0011", "01"

---

## Approach

Instead of generating all substrings, we use an optimized linear approach.

We track:

- `curr_group`: length of the current consecutive characters
- `prev_group`: length of the previous consecutive characters

Whenever the character changes:
- Add `min(prev_group, curr_group)` to the result
- Update `prev_group` to `curr_group`
- Reset `curr_group` to 1

At the end, add `min(prev_group, curr_group)` one final time.

This works because a valid binary substring is formed only between two consecutive groups.

---

## Algorithm

1. Initialize:
   - `prev_group = 0`
   - `curr_group = 1`
   - `result = 0`
2. Traverse the string from index 1.
3. If the current character matches the previous:
   - Increment `curr_group`
4. Else:
   - Add `min(prev_group, curr_group)` to result
   - Update `prev_group`
   - Reset `curr_group`
5. After the loop, add final `min(prev_group, curr_group)`
6. Return result

---

## Time and Space Complexity

Time Complexity: O(n)  
Space Complexity: O(1)

---

## File Structure

- solution.py → Python implementation
- README.md → Explanation and approach
