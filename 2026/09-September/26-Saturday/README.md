# LeetCode 1807 - Evaluate the Bracket Pairs of a String

## Problem

You are given a string `s` containing several pairs of brackets. Each bracket pair contains a key.

You are also given a 2D array `knowledge`, where:

* `knowledge[i][0]` is a key.
* `knowledge[i][1]` is the value associated with that key.

For every bracket pair `(key)` in the string:

* Replace it with its corresponding value if the key exists in `knowledge`.
* Replace it with `?` if the key does not exist.

Return the resulting string.

---

## Example

### Input

```text
s = "hi(name)"
knowledge = [["name","bob"]]
```

### Output

```text
"hi bob"
```

### Explanation

The bracket pair `(name)` corresponds to the value `"bob"` in `knowledge`.

---

## Approach

The solution uses a **Hash Map (Dictionary)** and a simple string traversal.

### Steps

1. Store every key-value pair from `knowledge` in a dictionary.
2. Traverse the string character by character.
3. When `(` is found:

   * Move forward until `)` is found.
   * Extract the key between the brackets.
   * Look up the key in the dictionary.
   * Append the corresponding value to the result.
   * If the key does not exist, append `?`.
4. For normal characters, directly append them to the result.
5. Join the result and return the final string.

---

## Python Solution

```python
class Solution:
    def evaluate(self, s: str, knowledge: list[list[str]]) -> str:
        mp = {key: value for key, value in knowledge}

        result = []
        i = 0

        while i < len(s):
            if s[i] == '(':
                j = i + 1

                while s[j] != ')':
                    j += 1

                key = s[i + 1:j]
                result.append(mp.get(key, '?'))

                i = j + 1
            else:
                result.append(s[i])
                i += 1

        return ''.join(result)
```

---

## Complexity Analysis

Let `n` be the length of the string `s` and `k` be the number of key-value pairs in `knowledge`.

### Time Complexity

```text
O(n + k)
```

Building the dictionary takes `O(k)`, and scanning the string takes `O(n)`.

### Space Complexity

```text
O(n + k)
```

`O(k)` space is used for the dictionary and `O(n)` space for the resulting string.

---

## Key Concepts

* Hash Map / Dictionary
* String Traversal
* String Parsing
* Linear Search
* `dict.get()`

---

## Important Python Technique

The dictionary can be created efficiently using:

```python
mp = {key: value for key, value in knowledge}
```

To return `?` when a key does not exist:

```python
mp.get(key, '?')
```

This avoids having to explicitly check:

```python
if key in mp:
    ...
else:
    ...
```

---

## Edge Cases

### 1. Unknown Key

```text
s = "(name)"
knowledge = []
```

Output:

```text
"?"
```

### 2. Multiple Bracket Pairs

```text
s = "hi(name)how(are)you"
knowledge = [["name","bob"],["are","you"]]
```

Output:

```text
"hibobhowyouyou"
```

### 3. Normal Characters

Characters outside brackets remain unchanged.

### 4. Repeated Keys

If the same key appears multiple times in the string, the same mapped value is used each time.

---

## Conclusion

The problem can be solved efficiently by storing the `knowledge` pairs in a dictionary and scanning the input string once. Dictionary lookup provides average `O(1)` access to each key, making the overall solution linear with respect to the input size.
