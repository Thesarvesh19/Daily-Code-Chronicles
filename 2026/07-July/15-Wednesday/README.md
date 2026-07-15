# 3658. GCD of Odd and Even Sums

## Problem Statement

Given an integer `n`, define:

- The sum of the first `n` odd numbers.
- The sum of the first `n` even numbers.

Return the **Greatest Common Divisor (GCD)** of these two sums.

---

## Examples

### Example 1

**Input**

```text
n = 4
```

**Calculation**

- Odd Sum = 1 + 3 + 5 + 7 = 16
- Even Sum = 2 + 4 + 6 + 8 = 20
- GCD(16, 20) = 4

**Output**

```text
4
```

---

### Example 2

**Input**

```text
n = 7
```

**Calculation**

- Odd Sum = 49
- Even Sum = 56
- GCD(49, 56) = 7

**Output**

```text
7
```

---

## Observation

The sum of the first `n` odd numbers is:

```text
1 + 3 + 5 + ... + (2n − 1) = n²
```

The sum of the first `n` even numbers is:

```text
2 + 4 + 6 + ... + 2n = n(n + 1)
```

We need to compute:

```text
gcd(n², n(n + 1))
```

Factor out `n`:

```text
= n × gcd(n, n + 1)
```

Since consecutive integers are always coprime:

```text
gcd(n, n + 1) = 1
```

Therefore,

```text
gcd(n², n(n + 1)) = n
```

Hence, the answer is simply:

```text
return n
```

---

## Algorithm

1. Read the integer `n`.
2. Return `n`.
3. No loops or additional computation are required.

---

## Correctness Proof

Let

- OddSum = `n²`
- EvenSum = `n(n + 1)`

Then,

```text
gcd(OddSum, EvenSum)
= gcd(n², n(n + 1))
= n × gcd(n, n + 1)
```

Because `n` and `n + 1` are consecutive integers,

```text
gcd(n, n + 1) = 1
```

Thus,

```text
gcd(OddSum, EvenSum) = n
```

Therefore, returning `n` always produces the correct answer.

---

## Complexity Analysis

- **Time Complexity:** `O(1)`
- **Space Complexity:** `O(1)`

---

## Key Mathematical Facts

- Sum of first `n` odd numbers = `n²`
- Sum of first `n` even numbers = `n(n + 1)`
- Consecutive integers are always coprime.
- Final answer = `n`.

---
