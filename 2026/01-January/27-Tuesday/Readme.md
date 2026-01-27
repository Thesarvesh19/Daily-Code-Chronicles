# Minimum Cost Path (Java)

This project contains a Java solution to find the **minimum cost to reach node `n - 1` from node `0`** in a weighted graph.

The graph is built such that:
- Each edge has a cost in one direction
- The reverse direction has double the cost

To solve this efficiently, **Dijkstra’s algorithm** is used with a priority queue.

### Approach
- Build an adjacency list from the given edges
- Use a min-heap (priority queue) to always process the node with the smallest cost
- Keep updating the shortest distance to each node
- Return the cost when the destination node is reached

### Time Complexity
- **O(E log V)**

### Space Complexity
- **O(V + E)**

### Language
- Java
