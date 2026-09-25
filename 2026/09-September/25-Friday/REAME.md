# 1096. Brace Expansion II

## Problem

Under a special rule, the expression is expanded into all possible strings.

An expression can contain:

- Lowercase English letters.
- `{}` braces.
- Commas `,` representing alternatives.
- Concatenation of expressions.

For example:

```text
{a,b} -> ["a", "b"]

{a,b}{c,d} -> ["ac", "ad", "bc", "bd"]

{a,{b,c}} -> ["a", "b", "c"]
```

Given a valid expression, return all possible strings in **lexicographical order** without duplicates.

### Example 1

```text
Input:
expression = "{a,b}{c,{d,e}}"

Output:
["ac","ad","ae","bc","bd","be"]
```

### Example 2

```text
Input:
expression = "{{a,z},a{b,c},{ab,z}}"

Output:
["a","ab","ac","z"]
```

---

## Approach

We can solve the problem using **Depth-First Search (DFS)**.

The main idea is:

1. Find the first closing brace `}`.
2. Find the matching opening brace `{`.
3. Extract the expression inside the braces.
4. Split the content using commas.
5. Replace the braces with each possible choice.
6. Recursively expand the newly created expression.
7. When no braces remain, insert the generated string into a `set`.

A `set` is useful because:

- It automatically removes duplicate strings.
- It stores strings in lexicographical order.

Finally, convert the set into a vector.

---

## Example Walkthrough

Consider:

```text
{a,b}{c,{d,e}}
```

The first brace expression is:

```text
{a,b}
```

It has two choices:

```text
a
b
```

So we recursively generate:

```text
a{c,{d,e}}
b{c,{d,e}}
```

Then `{c,{d,e}}` produces:

```text
c
d
e
```

Combining both parts gives:

```text
ac
ad
ae
bc
bd
be
```

The final answer is:

```text
["ac","ad","ae","bc","bd","be"]
```

---

## Python Solution

```python
from typing import List


class Solution:
    def braceExpansionII(self, expression: str) -> List[str]:
        result = set()

        def dfs(exp):
            # No braces left
            if '}' not in exp:
                result.add(exp)
                return

            # Find the first closing brace
            right = exp.find('}')

            # Find the matching opening brace
            left = exp.rfind('{', 0, right)

            # Parts before and after the braces
            prefix = exp[:left]
            suffix = exp[right + 1:]

            # Content inside the braces
            inside = exp[left + 1:right]

            # Try every comma-separated option
            for part in inside.split(','):
                dfs(prefix + part + suffix)

        dfs(expression)

        return sorted(result)
```

---

## C++ Solution

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    set<string> ans;

    void dfs(string exp) {
        // No braces left
        if (exp.find('}') == string::npos) {
            ans.insert(exp);
            return;
        }

        // Find the first closing brace
        int right = exp.find('}');

        // Find the matching opening brace
        int left = exp.rfind('{', right);

        // Extract prefix and suffix
        string prefix = exp.substr(0, left);
        string suffix = exp.substr(right + 1);

        // Extract content inside braces
        string inside = exp.substr(left + 1, right - left - 1);

        // Split by commas
        string part;
        stringstream ss(inside);

        while (getline(ss, part, ',')) {
            dfs(prefix + part + suffix);
        }
    }

    vector<string> braceExpansionII(string expression) {
        dfs(expression);

        return vector<string>(ans.begin(), ans.end());
    }
};
```

---

## Java Solution

```java
import java.util.*;

class Solution {

    private Set<String> ans = new TreeSet<>();

    public List<String> braceExpansionII(String expression) {
        dfs(expression);
        return new ArrayList<>(ans);
    }

    private void dfs(String exp) {

        // No braces left
        if (exp.indexOf('}') == -1) {
            ans.add(exp);
            return;
        }

        // Find the first closing brace
        int right = exp.indexOf('}');

        // Find matching opening brace
        int left = exp.lastIndexOf('{', right);

        // Extract prefix and suffix
        String prefix = exp.substring(0, left);
        String suffix = exp.substring(right + 1);

        // Extract content inside braces
        String inside = exp.substring(left + 1, right);

        // Split by commas
        String[] parts = inside.split(",");

        for (String part : parts) {
            dfs(prefix + part + suffix);
        }
    }
}
```

---

## Complexity Analysis

Let:

- `N` = length of the expression.
- `K` = number of distinct strings generated.

Since the number of possible expansions can be exponential, the output itself can contain exponentially many strings.

### Time Complexity

Approximately:

```text
O(K × N)
```

Additionally, the Python solution sorts the final result:

```text
O(K log K)
```

Therefore, the overall complexity can be considered:

```text
O(K × N + K log K)
```

### Space Complexity

The set stores all generated strings:

```text
O(K × N)
```

The recursive DFS also uses additional stack space.

---

## Key Concepts

- Recursion
- Depth-First Search
- String manipulation
- Set
- Lexicographical ordering
- Recursive expansion

---

## Why Use a Set?

Different expansion paths can generate the same string.

For example:

```text
{{a,b},a}
```

can generate:

```text
a
b
a
```

The duplicate `"a"` should appear only once.

Using a set automatically handles this:

```text
{"a", "b"}
```

In C++, `set<string>` and Java's `TreeSet<String>` also maintain lexicographical ordering.

---

## LeetCode

**Problem:** 1096. Brace Expansion II

**Difficulty:** Hard

**Topics:**

- String
- Backtracking
- Recursion
- Parsing
- Set
- Depth-First Search
