# LeetCode 2144. Minimum Cost of Buying Candies With Discount

## Problem Statement

A shop is selling candies where you can buy any two candies and get a third candy for free. The free candy must have a cost less than or equal to the cheaper of the two candies purchased. 

Given an integer array `cost`, where `cost[i]` represents the cost of the `i-th` candy, return the minimum amount of money required to buy all the candies.

---

## Examples

### Example 1

Input:

```text
cost = [1,2,3]
```

Output:

```text
5
```

Explanation:

* Buy candies costing 3 and 2.
* Get candy costing 1 for free.
* Total cost = 3 + 2 = 5.

### Example 2

Input:

```text
cost = [6,5,7,9,2,2]
```

Output:

```text
23
```

---

## Approach

To minimize the total amount spent, we should maximize the value of candies received for free.

### Key Observation

The free candy should be as expensive as possible. Therefore:

1. Sort the candies in descending order.
2. Consider candies in groups of three.
3. Pay for the first two candies in each group.
4. Skip the third candy because it becomes free.
5. Continue until all candies are processed.

After sorting:

```text
9, 7, 6, 5, 2, 2
```

Groups:

```text
(9, 7, 6) → 6 is free
(5, 2, 2) → 2 is free
```

Amount paid:

```text
9 + 7 + 5 + 2 = 23
```

---

## Algorithm

1. Sort the array in decreasing order.
2. Traverse the sorted array.
3. Add the cost of every candy except every third candy.
4. Return the accumulated sum.

---

## Dry Run

Input:

```text
cost = [6,5,7,9,2,2]
```

Sorted:

```text
[9,7,6,5,2,2]
```

Traversal:

| Index | Cost | Action |
| ----- | ---- | ------ |
| 0     | 9    | Pay    |
| 1     | 7    | Pay    |
| 2     | 6    | Free   |
| 3     | 5    | Pay    |
| 4     | 2    | Pay    |
| 5     | 2    | Free   |

Total:

```text
9 + 7 + 5 + 2 = 23
```

---

## Correctness Proof

After sorting in descending order, every group of three candies contains the highest available costs.

To maximize savings, the free candy should be the largest possible candy that can legally be obtained for free. By taking every third candy after sorting, we ensure that:

* The two most expensive candies in a group are purchased.
* The next most expensive eligible candy becomes free.
* No other arrangement can produce a larger discount.

Therefore, this greedy strategy always produces the minimum total cost.

---

## Complexity Analysis

### Time Complexity

Sorting the array takes:

```text
O(n log n)
```

Traversing the array takes:

```text
O(n)
```

Overall:

```text
O(n log n)
```

### Space Complexity

Only a few extra variables are used:

```text
O(1)
```

(ignoring the sorting implementation's internal space)

---

## Topics

* Array
* Sorting
* Greedy

---

## C++ Solution

```cpp
class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(), cost.end(), greater<int>());

        int ans = 0;

        for (int i = 0; i < cost.size(); i++) {
            if (i % 3 != 2)
                ans += cost[i];
        }

        return ans;
    }
};
```

---

## Key Takeaway

The problem looks like a discount optimization challenge, but it can be solved using a simple greedy observation:

> To maximize the discount, sort candies in descending order and make every third candy free.

This leads to an efficient and elegant solution with **O(n log n)** time complexity.
