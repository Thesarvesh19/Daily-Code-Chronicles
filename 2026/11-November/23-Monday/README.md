
# 1352. Product of the Last K Numbers

## Problem Description

Design a data structure that supports adding numbers to a sequence and returning the product of the last `k` numbers.

Implement the `ProductOfNumbers` class:

- `ProductOfNumbers()` Initializes the object with an empty stream.
- `void add(int num)` Adds `num` to the stream.
- `int getProduct(int k)` Returns the product of the last `k` numbers in the current stream.

## Approach: Prefix Products

We maintain a prefix product array to efficiently calculate the product of the last `k` numbers.

- Initialize the prefix array with `1`.
- Whenever a non-zero number is added, multiply it with the last prefix product and append the result.
- If `0` is added, reset the prefix array to `{1}` because any product involving zero is zero.
- To calculate the product of the last `k` numbers, divide the latest prefix product by the prefix product before those `k` numbers.
- If `k` is greater than or equal to the size of the prefix array, return `0`, since the requested range contains a zero.

## C++ Solution

```cpp
class ProductOfNumbers {
private:
    vector<int> prefix;

public:
    ProductOfNumbers() {
        prefix.push_back(1);
    }

    void add(int num) {
        if (num == 0) {
            prefix.clear();
            prefix.push_back(1);
        } else {
            prefix.push_back(prefix.back() * num);
        }
    }

    int getProduct(int k) {
        if (k >= prefix.size()) {
            return 0;
        }

        int n = prefix.size();
        return prefix[n - 1] / prefix[n - 1 - k];
    }
};
```

## Example

**Input:**

```text
["ProductOfNumbers","add","add","add","add","add","getProduct","getProduct","getProduct","getProduct","add","getProduct"]
[[],[3],[0],[2],[5],[4],[2],[3],[4],[1],[8],[2]]
```

**Output:**

```text
[null,null,null,null,null,null,20,40,0,4,null,32]
```

## Complexity Analysis

- **Time Complexity:** O(1) for both `add()` and `getProduct()`.
- **Space Complexity:** O(n), where `n` is the number of elements added since the last zero.
