# 940. Distinct Subsequences II

## Problem

Given a string `s`, return the number of **distinct non-empty subsequences** of `s`.

Since the answer can be very large, return it modulo:

`10^9 + 7`

---

## Approach: Dynamic Programming

Let `dp` represent the number of distinct non-empty subsequences formed so far.

When we process a new character:

* Every existing subsequence can either include or exclude the new character.
* The new character itself also forms a subsequence.
* Therefore, the initial calculation is:

```text
newDp = 2 * dp + 1
```

However, if the current character has appeared before, some subsequences will be counted twice.

We store the number of subsequences created when each character was previously processed and subtract those duplicates.

### Formula

```text
newDp = 2 * dp + 1 - last[current_character]
```

Then update:

```text
last[current_character] = dp + 1
dp = newDp
```

All operations are performed modulo `10^9 + 7`.

---

## Example

### Input

```text
s = "aba"
```

### Distinct Subsequences

```text
a
b
ab
aa
ba
aba
```

### Output

```text
6
```

---

## Complexity

* **Time Complexity:** `O(n)`
* **Space Complexity:** `O(1)` because there are only 26 lowercase English characters.

---

## C++ Solution

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int distinctSubseqII(string s) {
        const int MOD = 1e9 + 7;

        long long dp = 0;
        vector<long long> last(26, 0);

        for (char ch : s) {
            long long newDp = (2 * dp + 1) % MOD;

            int idx = ch - 'a';
            newDp = (newDp - last[idx] + MOD) % MOD;

            last[idx] = (dp + 1) % MOD;
            dp = newDp;
        }

        return dp;
    }
};
```
