# LeetCode 1752 - Check if Array Is Sorted and Rotated

## Problem
Given an array `nums`, return `true` if the array was originally sorted in non-decreasing order and then rotated some number of positions. Otherwise return `false`.

Example:

Input:
nums = [3,4,5,1,2]

Output:
true

Explanation:
Original sorted array:
[1,2,3,4,5]

After rotation:
[3,4,5,1,2]

---

## Approach

A sorted and rotated array can have **at most one decreasing point**.

Example:

[3,4,5,1,2]

Breaks:

3 < 4 → OK  
4 < 5 → OK  
5 > 1 → Break = 1  
1 < 2 → OK  
2 < 3 → OK  

Only one break → Valid

If breaks > 1 → Invalid

We compare the last element with first element using:

```cpp
(i + 1) % n
```

This creates circular checking.

---

## Algorithm

1. Initialize `count = 0`
2. Traverse array
3. If current element > next element:
      increment count
4. Return:

```cpp
count <= 1
```

---

## C++ Solution

```cpp
class Solution {
public:
    bool check(vector<int>& nums) {
        int count = 0;
        int n = nums.size();

        for(int i=0;i<n;i++){
            if(nums[i] > nums[(i+1)%n])
                count++;
        }

        return count <= 1;
    }
};
```

---

## Dry Run

Input:

```text
nums = [2,1,3,4]
```

Check:

2 > 1 → count=1  
1 > 3 → No  
3 > 4 → No  
4 > 2 → count=2  

count = 2

Return:

false

---

Input:

```text
nums=[3,4,5,1,2]
```

Breaks:

5 > 1 → count=1

Return:

true

---

