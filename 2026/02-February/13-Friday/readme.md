# 3714. Longest Balanced Substring II

## Problem

Given a string `s` consisting only of characters `'a'`, `'b'`, and `'c'`.

A substring is considered **balanced** if all distinct characters in that substring appear the same number of times.

Return the length of the longest balanced substring.

---

## Approach

Since the string contains only three characters, a balanced substring can fall into three categories:

### 1️⃣ Single Character
Any substring containing only one character is automatically balanced.

Example:
"aaa" → valid


Handled using a linear scan to find the longest consecutive run.

---

### 2️⃣ Exactly Two Distinct Characters
If a substring contains exactly two distinct characters, their frequencies must be equal.

Example:
"abba" → a = 2, b = 2


Approach:
- Convert the two characters into +1 and -1.
- Use prefix difference with a HashMap.
- Find longest subarray where difference is zero.

We repeat this for:
- (a, b)
- (b, c)
- (a, c)

---

### 3️⃣ All Three Characters
If all three characters are present, their counts must be equal.

Example:
"abcabc" → a = b = c = 2


Approach:
- Maintain prefix counts of a, b, c.
- Track two differences:
    - (a - b)
    - (b - c)
- If the same difference pair appears again, the substring between them is balanced.
- Store states using a HashMap.

---

## Final Answer

We compute:

max(
longest single-character substring,
longest valid two-character substring,
longest valid three-character substring
)


---

## Complexity

Time Complexity:  
O(n)


Space Complexity:  
O(n)
