# Add Binary

##  Problem Statement
 
Given two binary strings `a` and `b`, return their sum as a binary string.

You must simulate binary addition without converting the strings to integers directly.

---

##  Approach

###  Core Idea

We simulate binary addition manually (like elementary addition):

- Start from the rightmost digit of both strings
- Maintain a `carry`
- Add corresponding digits + carry
- Append `(sum % 2)` to result
- Update `carry = sum / 2`
- Reverse the result at the end

---

Binary addition rules:

| A | B | Carry | Result | New Carry |
|---|---|-------|--------|-----------|
| 0 | 0 | 0     | 0      | 0         |
| 1 | 0 | 0     | 1      | 0         |
| 1 | 1 | 0     | 0      | 1         |
| 1 | 1 | 1     | 1      | 1         |

We repeat until:
- both strings are exhausted
- and carry becomes 0

---

## ⏱ Time Complexity

O(max(n, m))


Where:
- n = length of string a
- m = length of string b

---

##  Space Complexity

O(max(n, m))


For storing result.

---

#  C++ Implementation

See `solution.cpp`

---

#  Python Implementation

```python
class Solution:
    def addBinary(self, a: str, b: str) -> str:
        i = len(a) - 1
        j = len(b) - 1
        carry = 0
        result = []

        while i >= 0 or j >= 0 or carry:
            total = carry

            if i >= 0:
                total += int(a[i])
                i -= 1

            if j >= 0:
                total += int(b[j])
                j -= 1

            result.append(str(total % 2))
            carry = total // 2

        return ''.join(result[::-1])
 Python Approach Explanation
Same logic as C++

Use list for result (faster than string concatenation)

Reverse at the end

No integer conversion of full string (avoids overflow)

 Edge Cases Covered
One string empty

Different length strings

Final carry exists

Both inputs "0"

Very large binary strings

 Example
Input:

a = "1010"
b = "1011"
Output:

