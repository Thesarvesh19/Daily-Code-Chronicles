# XOR After Range Multiplication Queries I

## Problem
You are given an array nums and a list of queries.

Each query has four values:
l, r, k, v

For each query:
- Start from index l
- Go to r with step k
- Multiply each selected element by v
- Take modulo (10^9 + 7) 

After all queries, return the XOR of all elements.

## Approach
We simulate each query directly.

Steps:
1. For each query, start from index l.
2. Move with step k until r.
3. Multiply each element by v and take modulo.
4. After processing all queries, calculate XOR of all elements.

## Time Complexity
O(n * q) in worst case.

## Space Complexity
O(1)

## Example
Input:
nums = [2,3,1,5,4]
queries = [[1,4,2,3],[0,2,1,2]]

Output:
31
