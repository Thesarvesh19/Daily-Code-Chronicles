# Binary Watch

## Problem Description

A binary watch has:
- 4 LEDs for hours (0 to 11)
- 6 LEDs for minutes (0 to 59)

Each LED represents a binary digit (0 or 1).  

Given an integer `turnedOn`, return all possible valid times that have exactly `turnedOn` LEDs turned on.
 
## Rules

1. The hour must not contain a leading zero.  
   Example: "01:00" is invalid, it should be "1:00"

2. The minute must always contain two digits.  
   Example: "10:2" is invalid, it should be "10:02"

3. 0 <= turnedOn <= 10

---

## Approach

We use a simple brute force method:

1. Iterate through all hours from 0 to 11.
2. Iterate through all minutes from 0 to 59.
3. Count the number of set bits (1s) in the binary form of:
   - hour
   - minute
4. If the total number of set bits equals `turnedOn`,
   format the time correctly and store it.
5. Return the list of valid times.

---

## Why This Works

There are only:

12 hours × 60 minutes = 720 possible combinations

Since 720 is small, checking every possible time is efficient.

---

## Time Complexity

O(720)  
This is constant time since the number of combinations is fixed.

---

## Space Complexity

O(1) excluding the output list.

---

## Files Included

- solution.kt
- solution.java
- solution.py
- solution.c

Each file follows the same logic adapted to its respective language.
