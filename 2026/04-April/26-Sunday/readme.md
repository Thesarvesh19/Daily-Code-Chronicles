#  Detect Cycles in a 2D Grid

##  Problem Summary
Given a 2D grid of characters, determine whether there exists a cycle of the same character.

A valid cycle:
- Has length ≥ 4
- Moves in 4 directions (up, down, left, right)
- Does not immediately revisit the previous cell

---

##  Approach: DFS (Depth-First Search)

- Traverse each cell
- Start DFS if not visited
- Move only to adjacent cells with same value
- Track parent cell to avoid trivial backtracking
- If a visited cell is reached again (not parent), cycle exists

---

##  Complexity

| Metric | Value |
|-------|------|
| Time  | O(m × n) |
| Space | O(m × n) |

---

##  Key Insight

This problem is equivalent to detecting cycles in an **undirected graph embedded in a grid**, with the additional constraint of matching characters.

---

##  Implementations Included

- Python (DFS)
- Java (DFS with class structure)
- C++ (STL-based DFS)
- C (Low-level recursive DFS)

---

##  When Cycle Exists

- Returning to an already visited node
- Not coming from its immediate parent

---

##  When No Cycle

- All paths terminate without revisiting nodes improperly

---

##  Conclusion

Efficient traversal + careful parent tracking ensures accurate cycle detection in linear time.
