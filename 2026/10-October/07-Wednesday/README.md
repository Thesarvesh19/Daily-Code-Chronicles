# LeetCode 301 - Remove Invalid Parentheses

## Problem

Given a string `s` that contains parentheses and English letters, remove the minimum number of invalid parentheses to make the input string valid.

Return all possible results. You may return the answer in any order.

A valid parentheses string must satisfy:

- Every opening parenthesis `(` has a corresponding closing parenthesis `)`.
- Parentheses are properly nested.
- Letters are allowed and do not affect validity.

---

## Examples

### Example 1

**Input:**

```text
s = "()())()"
```

**Output:**

```text
["(())()", "()()()"]
```

### Example 2

**Input:**

```text
s = "(a)())()"
```

**Output:**

```text
["(a())()", "(a)()()"]
```

### Example 3

**Input:**

```text
s = ")("
```

**Output:**

```text
[""]
```

---

## Approach

We use **Depth-First Search (DFS), Backtracking, Pruning, and a Two-Pass Technique**.

The main idea is to avoid generating every possible subsequence of the string.

Instead, we:

1. Scan the string from left to right.
2. Find the first position where the parentheses become invalid.
3. Try removing only the possible offending parenthesis.
4. Skip duplicate removals.
5. Once all extra `)` are removed, reverse the string.
6. Repeat the same process to remove extra `(`.
7. Store the resulting valid strings.

---

## Understanding the Balance

We maintain a `balance` variable.

For the normal pass:

```text
'(' -> balance + 1
')' -> balance - 1
```

For a valid parentheses sequence, the balance should never become negative.

For example:

```text
(()())
```

Balance changes as:

```text
( -> 1
( -> 2
) -> 1
( -> 2
) -> 1
) -> 0
```

This is valid.

But for:

```text
())(
```

the balance becomes:

```text
( -> 1
) -> 0
) -> -1
```

When the balance becomes negative, we know that there is an extra closing parenthesis `)`.

---

## Finding the First Invalid Position

Suppose:

```text
s = "()())()"
```

Scanning the string:

```text
( -> balance = 1
) -> balance = 0
( -> balance = 1
) -> balance = 0
) -> balance = -1
```

The first invalid position has been found.

At this point, we only try removing a `)` from the relevant range.

There is no need to continue exploring the rest of the current branch.

---

## Avoiding Duplicate Results

Consider:

```text
s = "()))"
```

There are multiple consecutive `)` characters.

Removing different identical `)` characters can produce the same string.

Therefore, we use:

```kotlin
if (
    s[j] == close &&
    (j == lastJ || s[j - 1] != close)
)
```

This ensures that consecutive identical parentheses are not removed from multiple equivalent positions.

This pruning is very important for both performance and avoiding duplicate results.

---

## Two-Pass Technique

The first pass handles extra closing parentheses:

```text
open  = '('
close = ')'
```

After all extra `)` characters have been removed, we reverse the string.

Then we swap the roles of the parentheses:

```text
open  = ')'
close = '('
```

This allows the exact same algorithm to find and remove extra `(` characters.

This is much cleaner than writing two separate algorithms.

---

## Kotlin Solution

```kotlin
class Solution {

    private fun removeInvalid(
        s: String,
        ans: MutableList<String>,
        lastI: Int,
        lastJ: Int,
        open: Char,
        close: Char
    ) {
        var balance = 0

        for (i in lastI until s.length) {

            when (s[i]) {
                open -> balance++
                close -> balance--
            }

            // The string is still valid
            if (balance >= 0) {
                continue
            }

            // We found an extra closing parenthesis
            for (j in lastJ..i) {

                // Avoid duplicate removals
                if (
                    s[j] == close &&
                    (j == lastJ || s[j - 1] != close)
                ) {
                    val next = s.removeRange(j, j + 1)

                    removeInvalid(
                        next,
                        ans,
                        i,
                        j,
                        open,
                        close
                    )
                }
            }

            // Only fix the first invalid position
            return
        }

        /*
         * No extra closing parenthesis remains.
         *
         * Reverse the string and solve the opposite
         * problem: removing extra opening parentheses.
         */
        val reversed = s.reversed()

        if (open == '(') {

            removeInvalid(
                reversed,
                ans,
                0,
                0,
                ')',
                '('
            )

        } else {

            // The string is completely valid
            ans.add(reversed)
        }
    }

    fun removeInvalidParentheses(s: String): List<String> {

        val ans = mutableListOf<String>()

        removeInvalid(
            s,
            ans,
            0,
            0,
            '(',
            ')'
        )

        return ans
    }
}
```

---

## Dry Run

Consider:

```text
s = "()())()"
```

### First Pass

We scan the string:

```text
( -> balance = 1
) -> balance = 0
( -> balance = 1
) -> balance = 0
) -> balance = -1
```

The balance becomes negative at the second extra `)`.

So we try removing the possible invalid `)`.

This generates candidates such as:

```text
(())()
()()()
```

The algorithm recursively checks these candidates.

---

## Reverse Pass

Once there are no extra `)` characters, the string is reversed.

The roles of the parentheses are exchanged.

For example:

```text
Original:
(((())

Reverse:
)(((( 
```

Now:

```text
')' behaves as open
'(' behaves as close
```

The same DFS logic can therefore remove extra `(` characters.

When the second pass finishes, the string is reversed back and added to the answer.

---

## Why We Do Not Use Simple Brute Force

A naive solution could try removing or keeping every character.

For every character, there are two possibilities:

```text
Keep it
Remove it
```

Therefore, the number of possibilities can approach:

```text
2^n
```

For large inputs, this generates huge numbers of unnecessary strings and can lead to:

```text
Memory Limit Exceeded
```

or:

```text
Time Limit Exceeded
```

The optimized approach avoids this by:

- Fixing only the first invalid position.
- Removing only possible offending parentheses.
- Skipping duplicate removals.
- Using the same logic for both types of invalid parentheses.

---

## Important Optimization

This condition is one of the most important parts of the solution:

```kotlin
if (
    s[j] == close &&
    (j == lastJ || s[j - 1] != close)
)
```

It prevents duplicate recursive states.

For example:

```text
s = "()))"
```

Instead of trying equivalent removals from every consecutive `)`, we only try the first relevant one.

---

## Another Important Optimization

After finding the first invalid position, we use:

```kotlin
return
```

This is important because we only need to fix the first point where the string becomes invalid.

Continuing to scan and branch from later positions would create many unnecessary recursive states.

---

## Correctness

The algorithm produces all valid strings with the minimum number of removals.

### Why?

Whenever the balance becomes negative, at least one `)` must be removed from the prefix containing that invalid position.

The algorithm tries every possible valid candidate for removing that offending `)` while skipping equivalent duplicate choices.

Once no extra `)` exists, the remaining problem can only involve extra `(`.

Reversing the string converts the problem of removing extra `(` into the same problem we already solved for extra `)`.

Therefore, the algorithm considers all minimum-removal possibilities without generating unnecessary invalid states.

---

## Complexity

Let `n` be the length of the input string.

The problem can have exponentially many valid answers, so exponential behavior is unavoidable in the worst case.

### Time Complexity

```text
O(2^n)
```

in the worst case.

However, the pruning and duplicate elimination make it significantly more efficient than naive brute force.

### Space Complexity

```text
O(n)
```

for the recursion stack, excluding the memory required to store the output.

The output itself can require exponential space when there are many valid answers.

---

## Key Concepts

- Depth-First Search
- Backtracking
- Recursion
- String Manipulation
- Pruning
- Duplicate Elimination
- Parentheses Matching
- Two-Pass DFS

---

## Key Takeaway

The complete strategy is:

```text
Find the first invalid parenthesis
            |
            v
Try removing only possible offending parentheses
            |
            v
Skip duplicate removals
            |
            v
Fix all extra ')'
            |
            v
Reverse the string
            |
            v
Swap '(' and ')' roles
            |
            v
Fix all extra '('
            |
            v
Store valid results
```

---

## Complexity Summary

| Property | Complexity |
|---|---|
| Time | O(2^n) worst case |
| Recursion Stack | O(n) |
| Output Space | Depends on number of valid answers |
| Technique | DFS + Backtracking + Pruning |
| Language | Kotlin |
| Difficulty | Hard |

---

## LeetCode

**Problem:** 301. Remove Invalid Parentheses

**Difficulty:** Hard

**Language:** Kotlin

**Topics:**

- String
- Backtracking
- Depth-First Search
- Recursion
- Pruning
- Parentheses
