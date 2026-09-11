# LeetCode 3483 - Unique 3-Digit Even Numbers

## Problem

You are given an array of digits. Return the number of **unique 3-digit even numbers** that can be formed using these digits.

Each digit can be used at most once for each number.

### Conditions

A valid number must:

* Have exactly **3 digits**.
* Not start with `0`.
* End with an **even digit**.
* Use different indices from the input array.

---

## Approach

We can try every possible choice of:

1. The hundreds digit.
2. The tens digit.
3. The units digit.

For each combination:

* Skip `0` as the hundreds digit.
* Make sure the same array index isn't used more than once.
* Check that the units digit is even.
* Construct the 3-digit number.
* Store it in a `HashSet` to automatically remove duplicates.

Finally, return the size of the set.

---

## Algorithm

1. Create an empty `HashSet`.
2. Iterate through every possible hundreds digit.
3. Skip it if it is `0`.
4. Iterate through every possible tens digit.
5. Skip the index if it was already used.
6. Iterate through every possible units digit.
7. Skip already-used indices.
8. Check if the units digit is even.
9. Construct the number.
10. Add it to the set.
11. Return the size of the set.

---

## Example

### Input

```text
digits = [1, 2, 3, 4]
```

Some valid numbers include:

```text
124
132
142
214
234
312
314
324
342
412
...
```

Only numbers ending in `2` or `4` are considered because the number must be even.

---

## Complexity

Let `n` be the number of digits.

### Time Complexity

```text
O(n³)
```

We use three nested loops to select the three digits.

### Space Complexity

```text
O(n³)
```

In the worst case, the set can contain `O(n³)` unique numbers.

Since `n <= 10`, this approach is easily fast enough.

---

## Java Solution

```java
import java.util.*;

class Solution {
    public int totalNumbers(int[] digits) {
        Set<Integer> nums = new HashSet<>();
        int n = digits.length;

        for (int i = 0; i < n; i++) {
            // Hundreds digit cannot be 0
            if (digits[i] == 0)
                continue;

            for (int j = 0; j < n; j++) {
                if (j == i)
                    continue;

                for (int k = 0; k < n; k++) {
                    if (k == i || k == j)
                        continue;

                    // Last digit must be even
                    if (digits[k] % 2 != 0)
                        continue;

                    int num = digits[i] * 100
                            + digits[j] * 10
                            + digits[k];

                    nums.add(num);
                }
            }
        }

        return nums.size();
    }
}
```

---

## Key Idea

The important observation is that there are only **three positions** to fill. By checking every possible combination of three different indices and using a `HashSet`, we can easily handle duplicate digits while counting only unique 3-digit even numbers.
