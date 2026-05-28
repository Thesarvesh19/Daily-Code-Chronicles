# LeetCode 3093 - Longest Common Suffix Queries

## Approach
We use a Trie built on reversed strings.

### Key Idea
- Insert every word from `wordsContainer` in reverse order.
- Store:
  - shortest word length
  - corresponding index
- For each query:
  - traverse reversed query
  - longest matched suffix gives answer

## Time Complexity
- Build Trie: O(N * L)
- Query: O(Q * L)

Where:
- N = number of container words
- Q = number of queries
- L = maximum string length

## Space Complexity
O(N * L)
