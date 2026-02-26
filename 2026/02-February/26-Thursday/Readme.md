# Number of Steps to Reduce a Binary Number to 1

##  Problem Statement

Given the binary representation of an integer as a string `s`, return the number of steps to reduce it to `1` under the following rules:

- If the current number is **even**, divide it by 2.
- If the current number is **odd**, add 1 to it.

It is guaranteed that you can always reach 1.

---

##  Approach

Since the binary number can be up to 500 bits long, converting it into an integer type may cause overflow.

So instead, we simulate the process directly on the binary string using `StringBuilder`.

###  Algorithm

1. While the string is not `"1"`:
   - If the last character is `'0'` → remove the last character (divide by 2).
   - If the last character is `'1'` → simulate binary addition:
     - Traverse backward while bits are `'1'`, change them to `'0'`.
     - If carry goes beyond the most significant bit, insert `'1'` at the beginning.
2. Count each operation.
3. Return total steps.

---

##  Example

### Input:

1101


### Output:

6


### Explanation:

1101 → 1110 → 111 → 1000 → 100 → 10 → 1


---

##  Complexity Analysis

- **Time Complexity:** O(n²) worst case  
- **Space Complexity:** O(n)



--
