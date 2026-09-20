# LeetCode 3498 - Reverse Degree of a String

## Problem

Given a string `s`, calculate its **reverse degree**.

The reverse degree of a string is calculated as follows:

- The reverse alphabetical value of a character is:
  - `a = 26`
  - `b = 25`
  - `c = 24`
  - ...
  - `z = 1`
- For each character, multiply its reverse alphabetical value by its **1-based position** in the string.
- Return the sum of all these products.

### Example

For:

```text
s = "abc"
