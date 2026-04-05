# Robot Return to Origin

## Problem Statement

A robot starts at position (0, 0) on a 2D plane. You are given a string `moves` that represents a sequence of movements. Each character in the string corresponds to a movement:

- U → move up   
- D → move down  
- L → move left  
- R → move right  

Each move changes the robot’s position by exactly one unit in the corresponding direction.

Your task is to determine whether the robot returns to the original position (0, 0) after performing all the moves.

---

## Examples

### Example 1
Input: moves = "UD"  
Output: true  

Explanation:  
The robot moves up once and then down once, returning to the starting point.

---

### Example 2
Input: moves = "LL"  
Output: false  

Explanation:  
The robot moves left twice and ends up at position (-2, 0), not at the origin.

---

## Constraints

- 1 <= moves.length <= 2 * 10^4  
- moves contains only the characters 'U', 'D', 'L', and 'R'

---

## Intuition

The robot moves on a 2D coordinate system. Instead of tracking the entire path, we only need to track the final position.

We can think of:
- Horizontal movement controlled by x
- Vertical movement controlled by y

If the robot returns to the origin, both x and y must be zero at the end.

---

## Approach

### Step-by-step explanation

1. Initialize two variables:
   - x = 0 (horizontal position)
   - y = 0 (vertical position)

2. Traverse through each character in the string:
   - If the move is 'U', increment y
   - If the move is 'D', decrement y
   - If the move is 'R', increment x
   - If the move is 'L', decrement x

3. After processing all moves:
   - Check if x == 0 and y == 0
   - If yes, return true
   - Otherwise, return false

---

## Why This Works

Each move has an opposite:
- U cancels D
- L cancels R

So, if the number of U equals D and the number of L equals R, the robot must return to the origin.

Tracking coordinates directly is a clean and efficient way to verify this condition.

---

## Alternative Approach

Instead of tracking coordinates, we can count characters:

- Count how many times U appears
- Count how many times D appears
- Count how many times L appears
- Count how many times R appears

Then check:

count(U) == count(D) AND count(L) == count(R)

---

## Complexity Analysis

### Time Complexity

O(n)

We iterate through the string once, where n is the length of the moves string.

---

### Space Complexity

O(1)

We only use a few variables (x and y), so no extra space is required.

---

## Edge Cases Considered

- Single move (cannot return to origin unless empty, which is not allowed here)
- All moves in one direction
- Balanced moves that cancel each other
- Large input size (up to 2 × 10^4 characters)

---

## Summary

This problem is a simple simulation task. The key idea is to track the net movement instead of the entire path. If both horizontal and vertical displacements are zero at the end, the robot returns to the origin.

This approach is efficient, easy to implement, and works within the given constraints.
