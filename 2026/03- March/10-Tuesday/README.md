# Find All Possible Stable Binary Arrays

## Problem

You are given three positive integers:

- `zero` — number of 0s  
- `one` — number of 1s  
- `limit` — maximum allowed consecutive identical numbers

A binary array is called **stable** if:

1. The number of occurrences of `0` is exactly `zero`.
2. The number of occurrences of `1` is exactly `one`.
3. Every subarray with length greater than `limit` must contain both `0` and `1`.

Return the total number of stable binary arrays.

Since the answer may be very large, return it modulo **10⁹ + 7**.

---

## Example

### Example 1

Input  
zero = 1  
one = 1  
limit = 2  

Output  
2  

Explanation  

Possible stable arrays:

[1,0]  
[0,1]

---

### Example 2

Input  
zero = 1  
one = 2  
limit = 1  

Output  
1  

Explanation  

Only valid array:

[1,0,1]

---

### Example 3

Input  
zero = 3  
one = 3  
limit = 2  

Output  
14

---

# Approach

We solve this problem using **Dynamic Programming**.

### State Definition

```
dp[i][j][k]
```

Where:

- `i` = number of zeros used
- `j` = number of ones used
- `k` = last element in the array
  - `0` → last element is 0
  - `1` → last element is 1

Meaning:

`dp[i][j][k]` represents the number of valid stable arrays using `i` zeros and `j` ones where the last element is `k`.

---

# Transition

### If the last element is `0`

We append `0` to previous arrays:

```
dp[i][j][0] =
dp[i-1][j][0] + dp[i-1][j][1]
```

But if we exceed the `limit` of consecutive zeros, we subtract invalid cases.

---

### If the last element is `1`

We append `1` to previous arrays:

```
dp[i][j][1] =
dp[i][j-1][0] + dp[i][j-1][1]
```

Similarly, we subtract invalid cases where ones exceed the limit.

---

# Initialization

Arrays containing only zeros or only ones are valid **only up to the limit**.

```
dp[i][0][0] = 1  for i ≤ limit
dp[0][j][1] = 1  for j ≤ limit
```

---

# Final Answer

```
result = dp[zero][one][0] + dp[zero][one][1]
```

Return the result modulo **10⁹ + 7**.

---

# Complexity Analysis

### Time Complexity

```
O(zero × one)
```

### Space Complexity

```
O(zero × one)
```

---

# Implementations

This repository contains implementations in multiple languages:

- Python → `solution.py`
- C++ → `solution.cpp`
- Java → `solution.java`
- Kotlin → `solution.kt`

