# 3310. Remove Methods From Project

## Problem
Given `n` methods, a starting suspicious method `k`, and a list of method invocations, determine which methods remain after removing all suspicious methods. A method is considered suspicious if it is reachable from `k`. However, if any suspicious method is connected to a non-suspicious method, then no methods should be removed.

## Approach
- Build a directed graph to represent method invocations.
- Perform DFS from the suspicious method `k` to mark all suspicious methods.
- Build an undirected version of the graph to identify connected components.
- Traverse every component containing non-suspicious methods and mark any connected suspicious methods as safe.
- Return all methods that are not suspicious after the traversal.

## Algorithm
1. Construct directed and undirected adjacency lists.
2. Run DFS from `k` on the directed graph.
3. Traverse connected components of non-suspicious methods in the undirected graph.
4. Mark any reachable suspicious methods in those components as safe.
5. Collect and return all remaining methods.

## Complexity
- **Time Complexity:** `O(n + m)`
- **Space Complexity:** `O(n + m)`

Where:
- `n` = Number of methods
- `m` = Number of invocations

