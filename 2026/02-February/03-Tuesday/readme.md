# Trionic Array Checker

This repository contains implementations to check whether an array is **trionic**.

An array is called **trionic** if it can be divided into **three consecutive parts**:

1. A **strictly increasing** sequence  
2. Followed by a **strictly decreasing** sequence  
3. Followed again by a **strictly increasing** sequence  

Each phase must contain **at least one element**, and all comparisons must be **strict**.

---

## Approach

The solution uses a **single pass** through the array and checks the three phases in order:

- Phase 1: Move forward while elements are strictly increasing  
- Phase 2: Continue while elements are strictly decreasing  
- Phase 3: Continue while elements are strictly increasing  

If all three phases are completed correctly and the array ends exactly at the end of phase 3, the array is trionic.

---

##  Time & Space Complexity

- **Time Complexity:** `O(n)`
- **Space Complexity:** `O(1)`

---

##  Implementations

- `solution.py` → Python implementation  
- `Solution.java` → Java implementation  

Both implementations follow the **same logic and behavior**, only differing in syntax.

---

##  Example

**Input:**  

[1, 3, 5, 4, 2, 6, 8]



**Output:**  

True
