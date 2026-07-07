# 3754. Concatenate Non-Zero Digits and Multiply by Sum I

## Problem

Given an integer `n`:

1. Concatenate all non-zero digits of `n` in their original order to form a new integer `x`.
2. Compute the sum of digits of `x`.
3. Return `x × sum`.

---

## Example

### Input

```
n = 10203004
```

### Output

```
12340
```

### Explanation

Non-zero digits:

```
1, 2, 3, 4
```

New number:

```
1234
```

Digit sum:

```
1 + 2 + 3 + 4 = 10
```

Answer:

```
1234 × 10 = 12340
```

---

## Algorithm

1. Traverse every digit of `n`.
2. Store only non-zero digits.
3. Restore their original order.
4. Construct the new integer.
5. Compute its digit sum.
6. Return `number × digitSum`.

---

## Complexity

- **Time:** O(log n)
- **Space:** O(1) auxiliary (or O(log n) if storing digits explicitly)

---

## Tags

- Math
- Simulation
- Number Manipulation
