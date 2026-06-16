# 3612. Process String with Special Operations I

## Problem Statement

You are given a string `s` containing:

* Lowercase English letters (`a-z`)
* Special characters:

  * `*` → Delete the last character of the current result.
  * `#` → Duplicate the current result and append it to itself.
  * `%` → Reverse the current result.

Process the string from left to right and return the final result.

---

## Example

### Input

```text
s = "a#b%*"
```

### Processing

| Character | Operation             | Result |
| --------- | --------------------- | ------ |
| a         | Append                | a      |
| #         | Duplicate             | aa     |
| b         | Append                | aab    |
| %         | Reverse               | baa    |
| *         | Remove last character | ba     |

### Output

```text
"ba"
```

---

# Intuition

The problem directly asks us to simulate operations on a string.

We maintain a mutable result:

* Add letters when encountered.
* Remove the last character for `*`.
* Append a copy of itself for `#`.
* Reverse itself for `%`.

Since operations must be executed in the given order, a simple simulation is sufficient.

---

# Approach

Traverse the string character by character.

For each character:

### Case 1: Lowercase Letter

Append it to the result.

```text
'a' -> result += 'a'
```

---

### Case 2: `*`

Remove the last character if the result is not empty.

```text
abc* -> ab
```

---

### Case 3: `#`

Duplicate the current result.

```text
abc# -> abcabc
```

---

### Case 4: `%`

Reverse the current result.

```text
abc% -> cba
```

---

# Algorithm

```text
Initialize empty result

For each character c in s:

    If c is a letter:
        append c

    Else if c == '*':
        remove last character if present

    Else if c == '#':
        duplicate current result

    Else if c == '%':
        reverse current result

Return result
```

---

# Complexity Analysis

Let:

```text
L = length of final generated string
```

### Time Complexity

```text
O(L)
```

Each character is processed once, and operations such as duplication or reversal work on the current result size.

---

### Space Complexity

```text
O(L)
```

We store the final generated string.

---

# Java Solution

```java
class Solution {
    public String processStr(String s) {
        StringBuilder res = new StringBuilder();

        for (char c : s.toCharArray()) {

            if (Character.isLowerCase(c)) {
                res.append(c);
            }

            else if (c == '*') {
                if (res.length() > 0) {
                    res.deleteCharAt(res.length() - 1);
                }
            }

            else if (c == '#') {
                res.append(res.toString());
            }

            else { // '%'
                res.reverse();
            }
        }

        return res.toString();
    }
}
```

---

# C Solution

```c
#include <stdlib.h>
#include <string.h>

char* processStr(char* s) {
    int cap = 1 << 20;
    char* res = (char*)malloc(cap);

    int len = 0;

    for (int i = 0; s[i]; i++) {

        if (s[i] >= 'a' && s[i] <= 'z') {
            res[len++] = s[i];
        }

        else if (s[i] == '*') {
            if (len > 0) len--;
        }

        else if (s[i] == '#') {
            memcpy(res + len, res, len);
            len *= 2;
        }

        else { // '%'
            for (int l = 0, r = len - 1; l < r; l++, r--) {
                char temp = res[l];
                res[l] = res[r];
                res[r] = temp;
            }
        }
    }

    res[len] = '\0';
    return res;
}
```

---

# C# Solution

```csharp
public class Solution {
    public string ProcessStr(string s) {

        List<char> res = new List<char>();

        foreach (char c in s) {

            if (char.IsLower(c)) {
                res.Add(c);
            }

            else if (c == '*') {
                if (res.Count > 0)
                    res.RemoveAt(res.Count - 1);
            }

            else if (c == '#') {
                res.AddRange(res.ToArray());
            }

            else { // '%'
                res.Reverse();
            }
        }

        return new string(res.ToArray());
    }
}
```

---

