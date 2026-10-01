
# LeetCode 20 - Valid Parentheses

## Problem Statement

Given a string `s` containing just the characters `'('`, `')'`, `'{'`, `'}'`, `'['` and `']'`, determine if the input string is valid.

An input string is valid if:

1. Open brackets must be closed by the same type of brackets.
2. Open brackets must be closed in the correct order.
3. Every closing bracket must have a corresponding opening bracket.

## Examples

### Example 1

**Input:**
```text
s = "()"
```

**Output:**
```text
true
```

### Example 2

**Input:**
```text
s = "()[]{}"
```

**Output:**
```text
true
```

### Example 3

**Input:**
```text
s = "(]"
```

**Output:**
```text
false
```

### Example 4

**Input:**
```text
s = "([)]"
```

**Output:**
```text
false
```

### Example 5

**Input:**
```text
s = "{[]}"
```

**Output:**
```text
true
```

## Approach: Stack (LIFO)

We use a Stack data structure to check whether the brackets are balanced and correctly ordered.

### Algorithm

1. Initialize an empty stack.
2. Traverse each character in the string.
3. If the character is an opening bracket `(`, `{`, or `[`, push it onto the stack.
4. If the character is a closing bracket:
   - Check whether the stack is empty.
   - If empty, return `false`.
   - Otherwise, pop the top element and check whether it matches the closing bracket.
5. If the brackets do not match, return `false`.
6. After processing all characters, return `true` if the stack is empty; otherwise, return `false`.

## Kotlin Solution

```kotlin
class Solution {
    fun isValid(s: String): Boolean {
        val stack = ArrayDeque<Char>()

        for (ch in s) {
            when (ch) {
                '(', '{', '[' -> stack.addLast(ch)

                ')' -> {
                    if (stack.isEmpty() || stack.removeLast() != '(') {
                        return false
                    }
                }

                '}' -> {
                    if (stack.isEmpty() || stack.removeLast() != '{') {
                        return false
                    }
                }

                ']' -> {
                    if (stack.isEmpty() || stack.removeLast() != '[') {
                        return false
                    }
                }
            }
        }

        return stack.isEmpty()
    }
}
```

## Complexity Analysis

Let `n` be the length of the input string.

- **Time Complexity:** `O(n)`
  - We traverse the string exactly once.
  - Each stack operation takes O(1) time.

- **Space Complexity:** `O(n)`
  - In the worst case, all characters are opening brackets and are stored in the stack.

## Key Concepts

- Stack Data Structure
- LIFO (Last In, First Out)
- String Traversal
- Conditional Statements
- Balanced Parentheses

## Edge Cases

| Input | Output | Explanation |
|---|---|---|
| `""` | `true` | Empty string |
| `"()"` | `true` | Valid pair |
| `"()[]{}"` | `true` | Multiple valid pairs |
| `"(]"` | `false` | Mismatched brackets |
| `"([)]"` | `false` | Incorrect order |
| `"((("` | `false` | Unclosed brackets |
| `")))"` | `false` | Closing brackets without opening brackets |
| `"{[]}"` | `true` | Properly nested brackets |

## Why Use a Stack?

A stack follows the LIFO (Last In, First Out) principle. This makes it suitable for checking balanced parentheses because the most recently opened bracket must be the first one to close.

## LeetCode Details

- **Platform:** LeetCode
- **Problem Number:** 20
- **Problem Name:** Valid Parentheses
- **Difficulty:** Easy
- **Topic:** Stack, String
- **Language:** Kotlin

## Author

**Sarvesh Soumil**

GitHub: https://github.com/Thesarvesh19
