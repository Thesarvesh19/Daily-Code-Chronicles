# LeetCode 1614 - Maximum Nesting Depth of the Parentheses

## Problem Statement
 
A string is a **valid parentheses string (VPS)** if it satisfies one of the following conditions:

- It is an empty string `""`.
- It can be written as `AB`, where both `A` and `B` are valid parentheses strings.
- It can be written as `(A)`, where `A` is a valid parentheses string.

The **nesting depth** of a VPS is defined as the maximum number of nested parentheses.

For example:

```text
"()"          -> 1
"(())"        -> 2
"((()))"      -> 3
