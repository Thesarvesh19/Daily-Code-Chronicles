# LeetCode 2904 - Shortest and Lexicographically Smallest Beautiful String

## Problem

Given a binary string `s` and an integer `k`, a substring is called **beautiful** if it contains exactly `k` occurrences of `1`.

Return the shortest beautiful substring of `s`.

If there are multiple beautiful substrings having the same minimum length, return the lexicographically smallest one.

If no beautiful substring exists, return an empty string.

---

## Approach

We use a **Sliding Window**.

### Steps

1. Maintain a window `[left, right]`.
2. Count the number of `1`s inside the current window.
3. If the count becomes greater than `k`, move `left` forward until the count becomes at most `k`.
4. When the window contains exactly `k` ones:
   - Remove unnecessary leading zeroes.
   - The resulting window is the shortest valid substring ending at `right`.
5. Compare it with the current answer:
   - Prefer the shorter substring.
   - If both have the same length, choose the lexicographically smaller one.

---

## Algorithm

```text
left = 0
ones = 0
answer = ""

for every right from 0 to n - 1:

    if s[right] == '1':
        increment ones

    while ones > k:
        if s[left] == '1':
            decrement ones
        move left forward

    while ones == k and s[left] == '0':
        move left forward

    if ones == k:
        current = s[left ... right]

        update answer if:
            current is shorter
            OR
            current has the same length but is lexicographically smaller

return answer
