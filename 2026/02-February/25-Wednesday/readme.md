# Sort Integers by The Number of 1 Bits

## Problem Statement

Given an integer array arr, sort the integers in ascending order by the number of 1's in their binary representation.

If two or more integers have the same number of 1's, sort them in ascending numerical order.

Return the sorted array.

--------------------------------------------------
 
## Example 1

Input:
arr = [0,1,2,3,4,5,6,7,8]

Output:
[0,1,2,4,8,3,5,6,7]

Explanation:
0 has 0 set bits
1,2,4,8 have 1 set bit
3,5,6 have 2 set bits
7 has 3 set bits

--------------------------------------------------

## Example 2

Input:
arr = [1024,512,256,128,64,32,16,8,4,2,1]

Output:
[1,2,4,8,16,32,64,128,256,512,1024]

All numbers have exactly 1 set bit.

--------------------------------------------------

## Approach

1. Count the number of set bits for each integer.
2. Sort the array:
   - First by number of set bits.
   - Then by numeric value if set bits are equal.

--------------------------------------------------

## Java Implementation

- Used Integer.bitCount() to count set bits.
- Used Arrays.sort() with custom comparator.

Time Complexity: O(n log n)  
Space Complexity: O(n)

--------------------------------------------------

## Python Implementation

- Used bin(x).count('1') to count set bits.
- Used sorted() with tuple-based sorting key.

Time Complexity: O(n log n)  
Space Complexity: O(n)

--------------------------------------------------

Constraints:
1 <= arr.length <= 500
0 <= arr[i] <= 10^4
