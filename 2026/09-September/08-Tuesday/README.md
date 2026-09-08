# LeetCode 3870 - Count Commas in Range

## Problem

Given an integer `n`, count the total number of commas used when writing all integers from `1` to `n` with standard comma formatting.

## Approach

For the given constraints:

* Numbers from `1` to `999` contain **0 commas**.
* Every number from `1000` to `n` contains **1 comma**.

Therefore:

* If `n < 1000`, the answer is `0`.
* Otherwise, the count of numbers from `1000` to `n` is:

```text
n - 999
```

## Complexity

* **Time Complexity:** `O(1)`
* **Space Complexity:** `O(1)`

## Implementations

### Python

```python
class Solution:
    def countCommas(self, n: int) -> int:
        return max(0, n - 999)
```

### Java

```java
class Solution {
    public int countCommas(int n) {
        return Math.max(0, n - 999);
    }
}
```

### C++

```cpp
class Solution {
public:
    int countCommas(int n) {
        return max(0, n - 999);
    }
};
```
