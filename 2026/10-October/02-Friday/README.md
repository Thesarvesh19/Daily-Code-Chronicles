# LeetCode 22 - Generate Parentheses

## Problem Statement

Given `n` pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

### Example 1

**Input:**

```text
n = 3
```

**Output:**

```text
["((()))","(()())","(())()","()(())","()()()"]
```

### Example 2

**Input:**

```text
n = 1
```

**Output:**

```text
["()"]
```

---

## Approach: Backtracking (DFS)

We use the Backtracking technique to generate all possible valid combinations of parentheses.

### Algorithm

1. Start with an empty string.
2. Add an opening parenthesis `(` if the number of opening parentheses is less than `n`.
3. Add a closing parenthesis `)` if the number of closing parentheses is less than the number of opening parentheses.
4. When the current string length becomes `2 * n`, add it to the result.
5. Continue exploring all valid combinations recursively.

### Python Solution

```python
class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        result = []

        def backtrack(current, open_count, close_count):
            if len(current) == 2 * n:
                result.append(current)
                return

            if open_count < n:
                backtrack(current + "(", open_count + 1, close_count)

            if close_count < open_count:
                backtrack(current + ")", open_count, close_count + 1)

        backtrack("", 0, 0)
        return result
```

### Java Solution

```java
import java.util.*;

class Solution {
    public List<String> generateParenthesis(int n) {
        List<String> result = new ArrayList<>();
        backtrack(result, new StringBuilder(), 0, 0, n);
        return result;
    }

    private void backtrack(List<String> result, StringBuilder current,
                           int open, int close, int n) {

        if (current.length() == 2 * n) {
            result.add(current.toString());
            return;
        }

        if (open < n) {
            current.append('(');
            backtrack(result, current, open + 1, close, n);
            current.deleteCharAt(current.length() - 1);
        }

        if (close < open) {
            current.append(')');
            backtrack(result, current, open, close + 1, n);
            current.deleteCharAt(current.length() - 1);
        }
    }
}
```

### C++ Solution

```cpp
class Solution {
public:
    void backtrack(vector<string>& result, string current,
                   int open, int close, int n) {

        if (current.length() == 2 * n) {
            result.push_back(current);
            return;
        }

        if (open < n) {
            backtrack(result, current + "(", open + 1, close, n);
        }

        if (close < open) {
            backtrack(result, current + ")", open, close + 1, n);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> result;
        backtrack(result, "", 0, 0, n);
        return result;
    }
};
```

---

## Complexity Analysis

Let `C(n)` represent the nth Catalan number.

* **Time Complexity:** `O(4^n / sqrt(n))` — proportional to the number of valid combinations.
* **Auxiliary Space Complexity:** `O(n)` for recursion depth, excluding the output.
* **Output Space Complexity:** `O(n * C(n))` for storing all valid combinations.

---

## Key Concepts

* Backtracking
* Depth First Search (DFS)
* Recursion
* String Manipulation
* Catalan Numbers

## LeetCode Information

* **Problem Number:** 22
* **Problem Name:** Generate Parentheses
* **Difficulty:** Medium
* **Platform:** LeetCode
* **Topics:** String, Dynamic Programming, Backtracking

## Conclusion

This problem demonstrates how backtracking can efficiently generate all valid combinations while avoiding invalid sequences.

By maintaining the count of opening and closing parentheses, we ensure that every generated combination is well-formed.
