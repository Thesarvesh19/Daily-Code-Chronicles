# Construct Uniform Parity Array II

## Approach

The goal is to check whether the array can satisfy the required parity condition.

1. Find the smallest odd number in the array.
2. If there are no odd numbers, return `true`.
3. Check every even number.
4. If any even number is smaller than the smallest odd number, return `false`.
5. Otherwise, return `true`.

## Algorithm

- Initialize `minOdd` with a large value.
- Traverse the array and find the minimum odd number.
- If no odd number exists, return `true`.
- Traverse the array again:
  - If an even number is smaller than `minOdd`, return `false`.
- Return `true`.

## Complexity

- **Time Complexity:** `O(n)`
- **Space Complexity:** `O(1)`

## C++

```cpp
class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int minOdd = INT_MAX;

        for (int x : nums1) {
            if (x % 2 != 0) {
                minOdd = min(minOdd, x);
            }
        }

        if (minOdd == INT_MAX) {
            return true;
        }

        for (int x : nums1) {
            if (x % 2 == 0 && x < minOdd) {
                return false;
            }
        }

        return true;
    }
};
