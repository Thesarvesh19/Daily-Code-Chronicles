# 3014. Minimum Number of Pushes to Type Word I

## Problem Overview

You are given a string `word` consisting of distinct lowercase English letters. The goal is to assign letters to the buttons of a phone keypad in a way that minimizes the total number of button presses required to type the word.

Each button can contain up to **8 letters**. The first letter assigned to a button requires **1 push**, the next group of up to 8 letters requires **2 pushes**, and so on.

Return the minimum number of pushes needed to type the given word.

## Approach

Since every character in the word is unique, only the number of characters matters.

To minimize the total pushes:

- The first **8** characters each require **1 push**.
- The next **8** characters each require **2 pushes**.
- The following **8** characters each require **3 pushes**, and so on.

For the character at index `i` (0-based), the required pushes are:

```text
pushes = (i / 8) + 1
```

Summing this value for every character gives the minimum number of pushes.

## Algorithm

1. Let `n` be the length of the word.
2. Initialize the answer to `0`.
3. Traverse the characters from left to right.
4. Add `(i / 8) + 1` for each character.
5. Return the accumulated answer.

## Correctness

- The cheapest positions are those requiring only one push.
- Each push level can accommodate at most **8 letters**.
- Assigning letters sequentially to the lowest available push level always minimizes the total cost.
- Therefore, adding `(i / 8) + 1` for every character produces the optimal answer.

## Complexity Analysis

- **Time Complexity:** `O(n)`
- **Space Complexity:** `O(1)`

## Implementations

This repository contains solutions in:

- Python
- Java
- C++
- C

## Key Idea

Instead of simulating a keypad, simply count how many push groups each character belongs to. Every block of 8 characters increases the required pushes by one, making the solution both simple and efficient.
