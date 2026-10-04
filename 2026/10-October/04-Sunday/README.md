# LeetCode 678 - Valid Parenthesis String

## Problem Statement

Given a string `s` containing only three types of characters: `'('`, `')'`, and `'*'`, return `true` if `s` is valid.

The following rules define a valid string:

1. Every left parenthesis `'('` must have a corresponding right parenthesis `')'`.
2. Every right parenthesis `')'` must have a corresponding left parenthesis `'('`.
3. Left parentheses must appear before their corresponding right parentheses.
4. `'*'` can be treated as a left parenthesis `'('`, a right parenthesis `')'`, or an empty string `""`.

## Examples

**Example 1:**

Input:
```text
s = "()"
```

Output:
```text
true
```

**Example 2:**

Input:
```text
s = "(*)"
```

Output:
```text
true
```

**Example 3:**

Input:
```text
s = "(*))"
```

Output:
```text
true
```

## Approach: Greedy Algorithm

We use two variables:

- `low`: Minimum possible number of unmatched opening parentheses.
- `high`: Maximum possible number of unmatched opening parentheses.

### Algorithm

1. Initialize `low = 0` and `high = 0`.
2. Traverse the string character by character.
3. If the character is `'('`, increment both `low` and `high`.
4. If the character is `')'`, decrement both `low` and `high`.
5. If the character is `'*'`, decrement `low` and increment `high`.
6. If `high` becomes negative, return `false`.
7. Keep `low` at least zero using `max(low, 0)`.
8. After processing the entire string, return `true` if `low == 0`.

## Python Solution

```python
class Solution:
    def checkValidString(self, s: str) -> bool:
        low = 0
        high = 0

        for ch in s:
            if ch == '(':
                low += 1
                high += 1

            elif ch == ')':
                low -= 1
                high -= 1

            else:
                low -= 1
                high += 1

            if high < 0:
                return False

            low = max(low, 0)

        return low == 0
```

## C++ Solution

```cpp
class Solution {
public:
    bool checkValidString(string s) {
        int low = 0, high = 0;

        for (char ch : s) {
            if (ch == '(') {
                low++;
                high++;
            }
            else if (ch == ')') {
                low--;
                high--;
            }
            else {
                low--;
                high++;
            }

            if (high < 0) {
                return false;
            }

            low = max(low, 0);
        }

        return low == 0;
    }
};
```

## Java Solution

```java
class Solution {
    public boolean checkValidString(String s) {
        int low = 0;
        int high = 0;

        for (int i = 0; i < s.length(); i++) {
            char ch = s.charAt(i);

            if (ch == '(') {
                low++;
                high++;
            }
            else if (ch == ')') {
                low--;
                high--;
            }
            else {
                low--;
                high++;
            }

            if (high < 0) {
                return false;
            }

            low = Math.max(low, 0);
        }

        return low == 0;
    }
}
```

## Complexity Analysis

Let `n` be the length of the input string.

| Complexity | Value | Explanation |
|---|---|---|
| Time Complexity | O(n) | The string is traversed once. |
| Space Complexity | O(1) | Only two variables are used. |

## Key Concepts

- Greedy Algorithm
- String Manipulation
- Parentheses Validation
- Range Tracking

## Key Takeaway

The Greedy approach efficiently solves the problem by tracking the minimum and maximum possible number of unmatched opening parentheses.

It avoids stack-based processing and achieves **O(n) time complexity and O(1) auxiliary space complexity**.

## LeetCode Details

- **Problem Number:** 678
- **Problem Name:** Valid Parenthesis String
- **Difficulty:** Medium
- **Topic:** Greedy, String
- **Languages:** Python, C++, Java

**Platform:** [LeetCode - Valid Parenthesis String](https://leetcode.com/problems/valid-parenthesis-string/)
