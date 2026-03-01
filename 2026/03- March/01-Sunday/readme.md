# Minimum Number of Deci-Binary Partitions

##  Problem Statement

A decimal number is called **deci-binary** if each of its digits is either `0` or `1` without any leading zeros.

Given a string `n` representing a positive decimal integer, return the **minimum number of positive deci-binary numbers** needed so that they sum up to `n`.

---

##  Key Insight

Each deci-binary number can contribute **at most 1** to any digit position.

So, if any digit in `n` is `d`, we need at least `d` deci-binary numbers to construct that digit.

###  Final Observation:
The answer is simply:

> **Maximum digit present in the string `n`**

---

##  Approach

1. Iterate through the string `n`.
2. Track the maximum digit.
3. Return that maximum digit.

---

##  Complexity Analysis

- **Time Complexity:** O(n)  
- **Space Complexity:** O(1)

---

##  Kotlin Implementation

```kotlin
class Solution {
    fun minPartitions(n: String): Int {
        var maxDigit = 0
        
        for (ch in n) {
            maxDigit = maxOf(maxDigit, ch - '0')
        }
        
        return maxDigit
    }
}
 Example
Example 1

Input: "32"
Output: 3
Explanation: 10 + 11 + 11 = 32

Example 2

Input: "82734"
Output: 8

