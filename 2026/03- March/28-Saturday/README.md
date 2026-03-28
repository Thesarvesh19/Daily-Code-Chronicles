
# Find the String with LCP

## Problem

You are given a matrix called lcp of size n x n.

lcp[i][j] represents the length of the longest common prefix between:
- substring starting at index i
- substring starting at index j

Your task is to construct a string of length n such that its lcp matrix matches the given matrix.

If multiple strings are possible, return the lexicographically smallest one.
If no valid string exists, return an empty string.

---

## Approach

Step 1: Check diagonal values  
Each lcp[i][i] must be equal to n - i.  
If not, return empty string.

Step 2: Group indices  
If lcp[i][j] > 0, then characters at index i and j must be same.  
We use Union-Find (DSU) to group such indices.

Step 3: Assign characters  
Each group gets a character starting from 'a'.  
This ensures smallest lexicographical result.

Step 4: Build string  
Assign characters to each index based on its group.

Step 5: Validate  
Rebuild the lcp matrix using the constructed string.  
If it does not match the input, return empty string.

---

## Complexity

Time Complexity: O(n^2)  
Space Complexity: O(n^2)

---

## Important Points

- Diagonal check is necessary
- Use DSU to group indices
- Maximum 26 groups allowed (a to z)
- Always validate final result

---

## Example

Input:
lcp = [[4,0,2,0],
       [0,3,0,1],
       [2,0,2,0],
       [0,1,0,1]]

Output:
abab

---

## Files

- solution.py : Python implementation
- solution.java : Java implementation
