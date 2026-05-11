# 2553. Separate the Digits in an Array

## Problem Statement
Given an array of positive integers `nums`, return an array `answer` that consists of the digits of each integer in `nums` after separating them in the same order they appear.

---

## Example 1

### Input
```text
nums = [13,25,83,77]
```

### Output
```text
[1,3,2,5,8,3,7,7]
```

---

## Example 2

### Input
```text
nums = [7,1,3,9]
```

### Output
```text
[7,1,3,9]
```

---

# Approach

We iterate through every number in the array and convert it into a string so that each digit can be accessed individually.

For every character in the string:
- Convert it back to an integer
- Store it in the result array

Finally, return the resulting array containing all separated digits.

---

# Algorithm

1. Create an empty result array.
2. Traverse each number in `nums`.
3. Convert the number into a string.
4. Traverse each character of the string.
5. Convert the character into an integer digit.
6. Append the digit to the result array.
7. Return the result array.

---

# Complexity Analysis

## Time Complexity
```text
O(n × d)
```

Where:
- `n` = number of elements in the array
- `d` = number of digits in each number

---

## Space Complexity
```text
O(n × d)
```

Extra space is used to store the separated digits.

---

# C++ Solution

```cpp
class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> result;

        for (int num : nums) {
            string s = to_string(num);

            for (char c : s) {
                result.push_back(c - '0');
            }
        }

        return result;
    }
};
```

---

# Java Solution

```java
class Solution {
    public int[] separateDigits(int[] nums) {
        List<Integer> list = new ArrayList<>();

        for (int num : nums) {
            String s = String.valueOf(num);

            for (char c : s.toCharArray()) {
                list.add(c - '0');
            }
        }

        int[] result = new int[list.size()];

        for (int i = 0; i < list.size(); i++) {
            result[i] = list.get(i);
        }

        return result;
    }
}
```

---

# Python Solution

```python
class Solution:
    def separateDigits(self, nums: List[int]) -> List[int]:
        result = []

        for num in nums:
            for digit in str(num):
                result.append(int(digit))

        return result
```

---

# JavaScript Solution

```javascript
var separateDigits = function(nums) {
    let result = [];

    for (let num of nums) {
        let digits = num.toString();

        for (let ch of digits) {
            result.push(parseInt(ch));
        }
    }

    return result;
};
```

---

# C# Solution

```csharp
public class Solution {
    public int[] SeparateDigits(int[] nums) {
        List<int> result = new List<int>();

        foreach (int num in nums) {
            string s = num.ToString();

            foreach (char c in s) {
                result.Add(c - '0');
            }
        }

        return result.ToArray();
    }
}
```

---

