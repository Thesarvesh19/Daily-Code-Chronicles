
# LeetCode 3723 - Maximize Sum of Squares of Digits

## Problem
Given two integers `num` and `sum`, construct a number with exactly `num` digits such that the sum of its digits equals `sum` and the sum of the squares of its digits is maximized.

## Approach: Greedy

1. If `sum > 9 * num`, return an empty string because no valid number can be formed.
2. Add as many `9`s as possible to maximize the sum of squared digits.
3. If a remainder exists, add it as the next digit.
4. Fill the remaining positions with zeros.
5. Return the resulting string.

## Python Solution

```python
class Solution:
    def maxSumOfSquares(self, num: int, sum: int) -> str:
        if sum > 9 * num:
            return ""

        k, rem = divmod(sum, 9)
        ans = "9" * k

        if rem:
            ans += str(rem)

        ans += "0" * (num - len(ans))
        return ans
```

## C++ Solution

```cpp
class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if (sum > 9 * num) return "";

        string ans = "";

        while (sum >= 9) {
            ans += '9';
            sum -= 9;
        }

        if (sum > 0) {
            ans += char('0' + sum);
        }

        while (ans.size() < num) {
            ans += '0';
        }

        return ans;
    }
};
```

## Java Solution

```java
class Solution {
    public String maxSumOfSquares(int num, int sum) {
        if (sum > 9 * num) return "";

        StringBuilder ans = new StringBuilder();

        while (sum >= 9) {
            ans.append('9');
            sum -= 9;
        }

        if (sum > 0) {
            ans.append(sum);
        }

        while (ans.length() < num) {
            ans.append('0');
        }

        return ans.toString();
    }
}
```

## Complexity Analysis

- **Time Complexity:** O(num)
- **Space Complexity:** O(num), for storing the resulting string.

## Key Takeaway

The greedy approach maximizes the sum of squared digits by placing as many `9`s as possible, followed by the remainder and zeros.
```

**Note:** Verify the exact problem statement and required method signature on LeetCode before submitting, as the solution above assumes the task is to construct a `num`-digit string whose digits sum to `sum` while maximizing the sum of their squares.
