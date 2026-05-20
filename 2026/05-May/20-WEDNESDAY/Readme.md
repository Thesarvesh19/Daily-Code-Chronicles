# 2657. Find the Prefix Common Array of Two Arrays

## Approach
Use a frequency array to count occurrences of elements from arrays A and B.

Whenever an element count becomes 2, it means the number has appeared in both arrays, so increment common count.

Store common count after every index.

## Complexity
- Time: O(n)
- Space: O(n)

## Languages
- C++
- Python
- Java
- Go
