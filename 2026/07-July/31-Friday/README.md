# LeetCode 3016 - Minimum Number of Pushes to Type Word II

## Problem Statement

Given a string `word`, assign its distinct letters to the buttons of a telephone keypad containing **8 keys**. Each key can store multiple letters.

- Typing the **first letter** on a key requires **1 push**.
- Typing the **second letter** on the same key requires **2 pushes**, and so on.

Return the **minimum total number of pushes** required to type the given word.

## Approach

The optimal strategy is to assign the **most frequent characters** to positions that require the fewest pushes.

### Algorithm

1. Count the frequency of each character.
2. Sort the frequencies in descending order.
3. Assign:
   - First 8 characters → 1 push
   - Next 8 characters → 2 pushes
   - Next 8 characters → 3 pushes
   - Remaining characters → 4 pushes
4. Multiply each frequency by its assigned push count and sum the results.

## Correctness

- Characters with higher frequencies contribute more to the total cost.
- Assigning them to positions with fewer required pushes minimizes the overall number of key presses.
- Sorting frequencies in descending order guarantees the minimum possible total cost.

## Complexity Analysis

- **Time Complexity:** `O(n log n)`
  - Counting frequencies takes `O(n)`.
  - Sorting at most 26 frequencies takes `O(26 log 26)`, which is constant, so the overall complexity is commonly written as `O(n log n)`.

- **Space Complexity:** `O(1)`
  - Only a fixed-size frequency array (26 lowercase letters) or equivalent data structure is used.

## Topics

- Greedy
- Sorting
- Hash Table
- String
- Counting

## Key Idea

Always assign the most frequent characters to the cheapest keypad positions (those requiring the fewest pushes). This greedy strategy produces the minimum total number of pushes.
