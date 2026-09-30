# LeetCode 1111 - Maximum Nesting Depth of Two Valid Parentheses Strings

## Problem

A parentheses string is valid if:

* It is an empty string.
* It can be written as `AB`, where both `A` and `B` are valid parentheses strings.
* It can be written as `(A)`, where `A` is a valid parentheses string.

The nesting depth of a valid parentheses string is the maximum number of nested parentheses.

For example:

`(())`

has a nesting depth of `2`.

Given a valid parentheses string `seq`, split it into two valid parentheses strings `A` and `B` such that:

`seq = A + B`

The goal is to minimize the maximum nesting depth between `A` and `B`.

Return an array `answer` of the same length as `seq`, where:

* `answer[i] = 0` means `seq[i]` belongs to `A`.
* `answer[i] = 1` means `seq[i]` belongs to `B`.

---

## Example 1

### Input

`seq = "(()())"`

### Output

`[1,0,0,0,0,1]`

One possible split is:

`A = ()()`

`B = ()`

Both strings are valid parentheses strings.

The maximum nesting depth of each string is minimized.

---

## Example 2

### Input

`seq = "()(())()"`

### Output

`[0,0,0,1,1,0,0,0]`

---

# Intuition

The main idea is to distribute nested parentheses between the two groups as evenly as possible.

Consider the nesting depth while traversing the string.

For example, if the current nesting depths are:

`1 -> 2 -> 3 -> 4`

we can alternate the groups:

* Depth `1` -> Group `1`
* Depth `2` -> Group `0`
* Depth `3` -> Group `1`
* Depth `4` -> Group `0`

This can be achieved using:

`depth % 2`

Therefore:

* Odd depth -> Group `1`
* Even depth -> Group `0`

This balances the nesting depth between the two resulting valid parentheses strings.

---

# Important Observation

For an opening parenthesis `(`:

1. Increase the current depth.
2. Assign the parenthesis according to the new depth.

For a closing parenthesis `)`:

1. Assign the parenthesis according to the current depth.
2. Decrease the depth.

Therefore:

For `(`:

`depth++`

`answer[i] = depth % 2`

For `)`:

`answer[i] = depth % 2`

`depth--`

This simple observation is enough to solve the problem in `O(n)` time.

---

# Algorithm

1. Initialize `depth = 0`.
2. Create an answer array.
3. Traverse every character of `seq`.
4. If the current character is `(`:

   * Increment `depth`.
   * Set the corresponding answer value to `depth % 2`.
5. Otherwise, the character is `)`:

   * Set the corresponding answer value to `depth % 2`.
   * Decrement `depth`.
6. Return the answer array.

---

# Dry Run

Consider:

`seq = "(()())"`

We process the characters one by one.

| Index | Character | Depth Before | Operation              | Depth After | Group |
| ----: | :-------: | -----------: | ---------------------- | ----------: | ----: |
|     0 |    `(`    |            0 | `depth++`              |           1 |     1 |
|     1 |    `(`    |            1 | `depth++`              |           2 |     0 |
|     2 |    `)`    |            2 | Assign, then `depth--` |           1 |     0 |
|     3 |    `(`    |            1 | `depth++`              |           2 |     0 |
|     4 |    `)`    |            2 | Assign, then `depth--` |           1 |     0 |
|     5 |    `)`    |            1 | Assign, then `depth--` |           0 |     1 |

Therefore:

`answer = [1,0,0,0,0,1]`

---

# Python Solution

```
class Solution:
    def maxDepthAfterSplit(self, seq: str) -> list[int]:
        ans = []
        depth = 0

        for ch in seq:
            if ch == '(':
                depth += 1
                ans.append(depth % 2)
            else:
                ans.append(depth % 2)
                depth -= 1

        return ans
```

---

# C++ Solution

```
class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int> ans;
        int depth = 0;

        for (char ch : seq) {
            if (ch == '(') {
                depth++;
                ans.push_back(depth % 2);
            } else {
                ans.push_back(depth % 2);
                depth--;
            }
        }

        return ans;
    }
};
```

---

# Java Solution

```
class Solution {
    public int[] maxDepthAfterSplit(String seq) {
        int n = seq.length();
        int[] ans = new int[n];
        int depth = 0;

        for (int i = 0; i < n; i++) {
            char ch = seq.charAt(i);

            if (ch == '(') {
                depth++;
                ans[i] = depth % 2;
            } else {
                ans[i] = depth % 2;
                depth--;
            }
        }

        return ans;
    }
}
```

---

# Complexity Analysis

Let `n` be the length of `seq`.

## Time Complexity

`O(n)`

We traverse the string exactly once.

## Space Complexity

`O(n)`

The answer array contains `n` elements.

The auxiliary space used apart from the output array is:

`O(1)`

---

# Why Does This Work?

Suppose the original valid parentheses string has maximum nesting depth `D`.

Every pair of nested parentheses occurs at consecutive depth levels.

By assigning:

* Odd depths to one group.
* Even depths to the other group.

The nested structure is distributed between the two groups.

For example:

`(((())))`

has nesting depths:

`1 2 3 4 4 3 2 1`

The assignments alternate between the two groups.

This prevents one group from containing the entire nesting depth of the original string.

Thus, the maximum nesting depth is balanced between the two groups.

---

# Key Formula

The entire solution is based on:

`depth % 2`

For an opening parenthesis:

`depth++`

`answer[i] = depth % 2`

For a closing parenthesis:

`answer[i] = depth % 2`

`depth--`

---

# Key Takeaway

Instead of explicitly constructing the two parentheses strings, we only need to determine which group each character belongs to.

The current nesting depth tells us the group:

`Group = depth % 2`

This gives a simple:

* Time Complexity: `O(n)`
* Auxiliary Space: `O(1)`
* Output Space: `O(n)`

solution.

---

# Tags

* Array
* String
* Stack
* Greedy
* Parentheses
* Nesting Depth
* LeetCode
* Medium

---

# LeetCode Details

**Problem Number:** 1111

**Problem Name:** Maximum Nesting Depth of Two Valid Parentheses Strings

**Difficulty:** Medium

**Languages:**

* Python
* C++
* Java
