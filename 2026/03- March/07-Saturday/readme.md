# Minimum Flips to Make Binary String Alternating

## Problem Description

You are given a binary string `s`. Two types of operations are allowed:

1. **Type-1 Operation**  
   Remove the first character of the string and append it to the end.

2. **Type-2 Operation**  
   Flip any character in the string:
   - '0' becomes '1'
   - '1' becomes '0'

Return the **minimum number of Type-2 operations** required to make the string **alternating**.

A string is alternating if no two adjacent characters are the same.

Examples of alternating strings:
- `010`
- `1010`

Examples of non-alternating strings:
- `0100`

---

## Examples

### Example 1
Input:

s = "111000"


Output:

2


Explanation:
Rotate twice to get `100011`, then flip the 3rd and 6th characters to obtain `101010`.

---

### Example 2
Input:

s = "010"


Output:

0


Explanation:  
The string is already alternating.

---

### Example 3
Input:

s = "1110"


Output:

1


Explanation:  
Flip the second character to get `1010`.

---

## Approach

Since **Type-1 operations allow rotations**, we must consider every possible rotation of the string.

Instead of generating all rotations (which would be inefficient), we use a trick:

1. Concatenate the string with itself:  

s2 = s + s

This allows every rotation of `s` to appear as a substring of length `n`.

2. There are only **two valid alternating patterns**:
- `010101...`
- `101010...`

3. Generate these patterns for length `2n`.

4. Use a **sliding window of size `n`** over `s2`.

5. Count mismatches with both patterns within the window.

6. The minimum mismatch count across all windows is the answer.

---

## Algorithm Steps

1. Let `n = len(s)`.
2. Create `s2 = s + s`.
3. Generate alternating patterns `alt1` and `alt2`.
4. Use a sliding window of size `n`.
5. Track mismatches for both patterns.
6. Update the minimum flips required.

---

## Complexity Analysis

**Time Complexity:**  

O(n)


We scan the string once using a sliding window.

**Space Complexity:**  

O(n)


