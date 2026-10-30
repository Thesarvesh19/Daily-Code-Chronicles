
# LeetCode 3970 - Shortest Path With At Most K Consecutive Identical Characters

## Problem Description
Find the minimum cost to travel from the source node to the destination node in a weighted directed graph while ensuring that no more than `k` consecutive nodes have identical labels.

If no valid path exists, return `-1`.

## Approach: Dijkstra's Algorithm + State-Based Shortest Path

### Intuition
A normal Dijkstra algorithm maintains the minimum distance for each node. However, in this problem, reaching the same node with different consecutive-character counts represents different states.

Therefore, we maintain:

`dist[node][count]`

Where:
- `node` represents the current node.
- `count` represents the number of consecutive identical labels.
- `dist[node][count]` stores the minimum cost to reach that state.

### Algorithm
1. Construct an adjacency list to represent the weighted directed graph.
2. Initialize a distance array of size `n × (k + 1)`.
3. Use a min-priority queue to process states in increasing order of cost.
4. For each adjacent node:
   - If its label matches the current node's label, increment the consecutive count.
   - Otherwise, reset the count to `1`.
5. Ignore transitions where the consecutive count exceeds `k`.
6. Update the distance if a cheaper valid path is found.
7. Return the minimum cost upon reaching the destination.
8. If no valid path exists, return `-1`.

## Complexity Analysis

Let:
- `V` = Number of vertices.
- `E` = Number of edges.
- `K` = Maximum allowed consecutive identical characters.

| Complexity | Value |
|---|---|
| Time Complexity | `O((V + E) * K * log(V * K))` |
| Space Complexity | `O(V * K + E)` |

## Key Concepts
- Graph Theory
- Dijkstra's Algorithm
- Priority Queue (Min Heap)
- State-Based Dynamic Programming
- Shortest Path Optimization

## Language
C++

## Solution
The solution uses Dijkstra's algorithm with an expanded state consisting of the current node and the consecutive-character count. This ensures that different valid path conditions are handled independently.

