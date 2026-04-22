# Words Within Two Edits of Dictionary

## Problem Summary
Given two arrays of equal-length strings:
- queries
- dictionary

Return all query words that can be transformed into any dictionary word using at most 2 edits.

## Key Concept
Count character differences (Hamming Distance)
 
If differences <= 2, the word is valid.

## Implementations
- Python (zip-based comparison)
- Java (helper method)
- C (pointer-based traversal)

## Complexity
- Time: O(Q × D × N)
- Space: O(1)

## Optimization
Early stopping when mismatches exceed 2

## Example
Input:
queries = ["word","note","ants","wood"]
dictionary = ["wood","joke","moat"]

Output:
["word","note","wood"]

## Takeaway
Brute force works efficiently due to small constraints and early pruning.
