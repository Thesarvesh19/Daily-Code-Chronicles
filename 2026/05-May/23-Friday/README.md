# 33. Search in Rotated Sorted Array

## Problem Statement
Given a rotated sorted array `nums` (distinct integers) and an integer `target`, return the index of `target` if it exists in the array. Otherwise, return `-1`.

You must write an algorithm with **O(log n)** runtime complexity.

### Example 1
Input:
nums = [4,5,6,7,0,1,2]
target = 0

Output:
4

### Example 2
Input:
nums = [4,5,6,7,0,1,2]
target = 3

Output:
-1

### Example 3
Input:
nums = [1]
target = 0

Output:
-1

---

## Approach: Binary Search

Since the array is rotated, one half of the array is always sorted.

Steps:
1. Find the middle element.
2. Check if target equals middle.
3. Determine which side is sorted:
   - Left half sorted
   - Right half sorted
4. Check if target belongs to the sorted half.
5. Discard the other half.
6. Repeat until target is found.

---

## C++ Solution

```cpp
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1;

        while(left <= right){
            int mid = left + (right-left)/2;

            if(nums[mid] == target)
                return mid;

            if(nums[left] <= nums[mid]){

                if(target >= nums[left] &&
                   target < nums[mid])
                    right = mid-1;
                else
                    left = mid+1;

            }else{

                if(target > nums[mid] &&
                   target <= nums[right])
                    left = mid+1;
                else
                    right = mid-1;
            }
        }

        return -1;
    }
};
```

---

## Python Solution

```python
class Solution:
    def search(self, nums, target):
        left, right = 0, len(nums)-1

        while left <= right:
            mid = (left+right)//2

            if nums[mid] == target:
                return mid

            if nums[left] <= nums[mid]:

                if nums[left] <= target < nums[mid]:
                    right = mid-1
                else:
                    left = mid+1

            else:

                if nums[mid] < target <= nums[right]:
                    left = mid+1
                else:
                    right = mid-1

        return -1
```

---

## Java Solution

```java
class Solution {
    public int search(int[] nums, int target) {

        int left = 0;
        int right = nums.length - 1;

        while(left <= right){

            int mid = left + (right-left)/2;

            if(nums[mid] == target)
                return mid;

            if(nums[left] <= nums[mid]){

                if(target >= nums[left]
                   && target < nums[mid])
                    right = mid-1;
                else
                    left = mid+1;

            }else{

                if(target > nums[mid]
                   && target <= nums[right])
                    left = mid+1;
                else
                    right = mid-1;
            }
        }

        return -1;
    }
}
```

