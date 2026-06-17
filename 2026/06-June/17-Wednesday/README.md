# 3614. Process String with Special Operations II

## Problem Overview

You are given a string `s` containing lowercase English letters and special operation characters:

* `'*'` → Remove the last character of the current string (if it exists).
* `'#'` → Duplicate the entire current string.
* `'%'` → Reverse the current string.

Instead of constructing the final string, you are asked to determine the character at index `k` in the final result.

If the index does not exist, return `'.'`.

---

## Example

### Input

```text
s = "a#b%"
k = 2
```

### Operations

```text
Start: ""

'a'  -> "a"
'#'  -> "aa"
'b'  -> "aab"
'%'  -> "baa"
```

Final String:

```text
"baa"
```

Character at index `2`:

```text
'a'
```

### Output

```text
'a'
```

---

# Key Observation

The final string can become extremely large.

For example:

```text
a####################
```

Every `#` doubles the string length.

After many duplications, the resulting string size can exceed:

```text
10^15
```

Building such a string would cause:

* Memory Limit Exceeded
* Time Limit Exceeded

Therefore, we need another approach.

---

# Efficient Idea

Instead of generating the final string:

1. Calculate only the final length.
2. Work backwards through the operations.
3. Track where position `k` came from before each operation.

This technique is called:

```text
Reverse Simulation
```

---

# Step 1: Compute Final Length

Traverse the string once.

Rules:

### Normal Character

```text
length += 1
```

### '*'

```text
length = max(0, length - 1)
```

### '#'

```text
length *= 2
```

### '%'

Length remains unchanged.

---

# Step 2: Check Validity

If:

```text
k >= finalLength
```

then the position does not exist.

Return:

```text
'.'
```

---

# Step 3: Reverse Traversal

Process operations from right to left.

We continuously transform index `k` into its previous position.

---

## Case 1: '#'

Forward:

```text
ABC
↓
ABCABC
```

Length doubled.

Backward:

```text
length /= 2
```

If:

```text
k >= length
```

then it belongs to the second copy.

Map it back:

```text
k -= length
```

---

## Case 2: '%'

Forward:

```text
ABC
↓
CBA
```

Backward:

```text
k = length - 1 - k
```

---

## Case 3: '*'

Forward:

```text
ABC
↓
AB
```

Backward:

```text
length += 1
```

The deleted character position is restored.

---

## Case 4: Normal Character

A character was appended.

Backward:

```text
length--
```

If:

```text
k == length
```

then this appended character is exactly the answer.

Return it immediately.

---

# Dry Run

## Input

```text
s = "ab#%"
k = 1
```

### Forward Length Calculation

```text
a  -> 1
b  -> 2
#  -> 4
%  -> 4
```

Final length:

```text
4
```

---

### Reverse Traversal

Start:

```text
k = 1
length = 4
```

#### '%'

```text
k = 4 - 1 - 1
k = 2
```

#### '#'

```text
length = 2
k >= 2
```

Yes:

```text
k = 2 - 2 = 0
```

#### 'b'

```text
length = 1
k != 1
```

Continue.

#### 'a'

```text
length = 0
k == 0
```

Answer:

```text
'a'
```

---

# Correctness

The algorithm never constructs the actual string.

Instead:

* Every operation is reversed mathematically.
* The index is traced back to its original source.
* Once the originating character is found, it must be the character occupying position `k` in the final string.

Therefore the algorithm always returns the correct answer.

---

# Complexity Analysis

## Time Complexity

```text
O(n)
```

Two passes over the string:

1. Length computation
2. Reverse simulation

---

## Space Complexity

```text
O(1)
```

Only a few variables are used.

---

# Why This Works

The naive approach tries to build the entire resulting string.

That can become astronomically large because:

```text
# doubles the size
```

Repeated duplications quickly exceed memory limits.

The reverse-simulation approach only tracks:

* Current length
* Target index

making it extremely efficient and suitable for large constraints.

---

# Tags

* String
* Simulation
* Reverse Simulation
* Math
* Greedy
* Index Mapping
