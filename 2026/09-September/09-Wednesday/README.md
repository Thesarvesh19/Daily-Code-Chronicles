# LeetCode 3871 — Count Commas in Range II

## Problem

Given an integer `n`, count the total number of commas that would appear if all integers from `1` to `n` were written with commas as thousands separators.

For example:

* `1000` → `1,000` → 1 comma
* `10000` → `10,000` → 1 comma
* `1000000` → `1,000,000` → 2 commas

Return the total number of commas.

---

## Approach

We do not need to check every number individually.

A comma appears at every group of three digits:

* Numbers from `1000` onward have at least **1 comma**.
* Numbers from `1,000,000` onward have at least **2 commas**.
* Numbers from `1,000,000,000` onward have at least **3 commas**.
* And so on.

For every threshold `x = 1000, 1000000, 1000000000, ...`:

* There are `n - x + 1` numbers from `x` to `n`.
* Each of these numbers contributes one additional comma.

So we add:

```text
n - x + 1
```

and then multiply `x` by `1000` to move to the next comma position.

---

## C++ Solution

```cpp
class Solution {
public:
    long long countCommas(long long n) {
        long long ans = 0;

        for (long long x = 1000; x <= n; x *= 1000) {
            ans += n - x + 1;
        }

        return ans;
    }
};
```

---

## Example

### Input

```text
n = 1002
```

Numbers containing a comma:

```text
1000 → 1,000
1001 → 1,001
1002 → 1,002
```

Therefore:

```text
Answer = 3
```

---

## Complexity

* **Time Complexity:** `O(log₁₀ n)`
* **Space Complexity:** `O(1)`

The loop runs once for every additional group of three digits.
