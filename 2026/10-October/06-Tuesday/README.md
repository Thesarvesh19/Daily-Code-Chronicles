# LeetCode 921 - Minimum Add to Make Parentheses Valid

## Problem

A parentheses string is valid if and only if:

- It is an empty string.
- It can be written as `AB`, where both `A` and `B` are valid strings.
- It can be written as `(A)`, where `A` is a valid string.

Given a parentheses string `s`, return the **minimum number of parentheses** you must add to make the resulting string valid.

### Example 1

```text
Input:  s = "())"
Output: 1
```

Explanation:

```text
"())" → "()()"
```

One `(` needs to be added.

### Example 2

```text
Input:  s = "((("
Output: 3
```

Explanation:

Three `)` need to be added.

### Example 3

```text
Input:  s = "()))(("
Output: 4
```

---

## Approach

We can solve the problem using a simple **balance counter**.

### Variables

- `balance` → Number of unmatched opening parentheses `(`.
- `additions` → Number of opening parentheses `(` that need to be added.

### Algorithm

1. Traverse the string from left to right.
2. If the current character is `(`:
   - Increase `balance`.
3. If the current character is `)`:
   - If `balance > 0`, match it with an existing `(` and decrease `balance`.
   - Otherwise, there is no matching `(`, so we need to add one:
     - Increase `additions`.
4. After traversing the entire string:
   - Every remaining unmatched `(` requires one `)`.
   - Therefore, the answer is:

```text
additions + balance
```

---

## Java Solution

```java
class Solution {
    public int minAddToMakeValid(String s) {
        int balance = 0;
        int additions = 0;

        for (char ch : s.toCharArray()) {
            if (ch == '(') {
                balance++;
            } else {
                if (balance > 0) {
                    balance--;
                } else {
                    additions++;
                }
            }
        }

        return additions + balance;
    }
}
```

---

## Python Solution

```python
class Solution:
    def minAddToMakeValid(self, s: str) -> int:
        balance = 0
        additions = 0

        for ch in s:
            if ch == '(':
                balance += 1
            else:
                if balance > 0:
                    balance -= 1
                else:
                    additions += 1

        return additions + balance
```

---

## Dry Run

Consider:

```text
s = "()))(("
```

| Character | Balance | Additions | Explanation |
|---|---:|---:|---|
| `(` | 1 | 0 | Opening parenthesis |
| `)` | 0 | 0 | Matches `(` |
| `)` | 0 | 1 | No matching `(`, add one |
| `)` | 0 | 2 | No matching `(`, add one |
| `(` | 1 | 2 | Opening parenthesis |
| `(` | 2 | 2 | Opening parenthesis |

At the end:

```text
additions = 2
balance = 2
answer = 2 + 2 = 4
```

Therefore:

```text
Output: 4
```

---

## Complexity Analysis

Let `n` be the length of the string.

### Time Complexity

```text
O(n)
```

We traverse the string exactly once.

### Space Complexity

```text
O(1)
```

Only two integer variables are used.

---

## Key Insight

The important idea is that every `)` must have a corresponding `(` before it.

If a `)` appears when `balance == 0`, we must add an `(`.

After processing the entire string, any remaining unmatched `(` require corresponding `)`.

Therefore:

```text
Minimum additions = unmatched ')' + unmatched '('
                 = additions + balance
```

---

## Tags

- String
- Stack
- Greedy
- Parentheses
- Counting
- LeetCode
- Easy

## LeetCode

**Problem:** 921 - Minimum Add to Make Parentheses Valid

**Difficulty:** Easy
