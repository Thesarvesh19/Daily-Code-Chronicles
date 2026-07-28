# LeetCode 3517: Smallest Palindromic Rearrangement I

A collection of optimal solutions in **Python**, **C**, **C++**, **C#**, and **Java** for LeetCode 3517.

---

## 📌 Problem Description

Given a string `s` that is guaranteed to be a palindrome, return the **lexicographically smallest** palindrome that can be formed by rearranging the characters of `s`.

### Constraints
- `1 <= s.length <= 10^5`
- `s` consists only of lowercase English letters.
- `s` is guaranteed to be a valid palindrome.

---

## 💡 Key Insight & Approach

Since `s` is already a palindrome:
1. **Extract the First Half:** Any valid rearranged palindrome must mirror its left half.
2. **Sort Lexicographically:** To make the palindrome lexicographically smallest, sort the characters of the first half in ascending order ($a \to z$).
3. **Handle Middle Character:** If the length of `s` is odd, retain the center character in place.
4. **Mirror:** Reverse the sorted first half to form the second half, and concatenate: `[Sorted Left] + [Middle] + [Reversed Sorted Left]`.

---
