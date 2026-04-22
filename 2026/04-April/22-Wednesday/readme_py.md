# Python Solution - Two Edit Words

## Idea
We compare each query word with every dictionary word and count character differences.

## Approach
- Use zip() for comparison
- Count mismatches
- Stop early if more than 2 differences

## Complexity
- Time: O(Q * D * N)
- Space: O(1)

## Features
- Clean implementation
- Early break optimization
