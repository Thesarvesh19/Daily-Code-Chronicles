# LeetCode 3622 - Check Divisibility by Digit Sum and Product

## Problem

Given a positive integer `n`, check whether `n` is divisible by the sum of its digits plus the product of its digits.

Return `true` if:

`n % (digitSum + digitProduct) == 0`

Otherwise, return `false`.

---

## Approach

1. Store the original value of `n`.
2. Extract each digit using `n % 10`.
3. Add the digit to `digitSum`.
4. Multiply the digit into `digitProduct`.
5. Remove the last digit using `n /= 10`.
6. Check whether the original number is divisible by:
   
   `digitSum + digitProduct`

---

## C++ Solution

```cpp
class Solution {
public:
    bool checkDivisibility(int n) {
        int original = n;
        int sum = 0;
        int product = 1;

        while (n > 0) {
            int digit = n % 10;

            sum += digit;
            product *= digit;

            n /= 10;
        }

        return original % (sum + product) == 0;
    }
};
