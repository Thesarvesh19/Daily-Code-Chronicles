# 788. Rotated Digits

## Problem Statement
A number is called good if after rotating each digit individually by 180 degrees, we get a valid number that is different from the original.

### Digit Rotation Rules
- 0 → 0  
- 1 → 1  
- 2 ↔ 5  
- 6 ↔ 9  
- 8 → 8   

### Invalid Digits
- 3, 4, 7 → make the number invalid

---

## Objective
Given an integer `n`, return the number of good numbers in the range `[1, n]`.

---

## Approach
We iterate from `1` to `n` and check each number:

### A number is valid if:
- It contains only valid digits (0, 1, 2, 5, 6, 8, 9)

### A number is good if:
- It is valid AND
- It contains at least one digit from `{2, 5, 6, 9}` (it changes after rotation)

---

## Algorithm
1. Loop from `1` to `n`
2. For each number:
   - Extract digits
   - If any digit is `3, 4, 7`, skip the number
   - Check if at least one digit is `2, 5, 6, 9`
3. Count such numbers

---

## Java Implementation
```java
class Solution {
    public int rotatedDigits(int n) {
        int count = 0;
        
        for (int i = 1; i <= n; i++) {
            if (isGood(i)) count++;
        }
        
        return count;
    }
    
    private boolean isGood(int num) {
        boolean changed = false;
        
        while (num > 0) {
            int digit = num % 10;
            
            if (digit == 3 || digit == 4 || digit == 7)
                return false;
            
            if (digit == 2 || digit == 5 || digit == 6 || digit == 9)
                changed = true;
            
            num /= 10;
        }
        
        return changed;
    }
}
