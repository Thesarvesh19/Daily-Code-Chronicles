# LeetCode 3120 — Count the Number of Special Characters I

## Problem
Given a string `word`, return the number of special characters.

A character is special if:

- Its lowercase form exists
- Its uppercase form also exists

Example:

Input:
word = "aaAbcBC"

Output:
3

Explanation:
Special characters:
a -> A
b -> B
c -> C

Answer = 3

---

## Approach

1. Store lowercase letters in one set
2. Store uppercase letters in another set
3. Convert uppercase letters to lowercase
4. Count intersection of both sets

Time Complexity:

O(n)

Space Complexity:

O(1)

(At most 26 English letters)

---

Languages Included:

- Python
- Java
- C++
- JavaScript
- Go
- C#
- Kotlin
