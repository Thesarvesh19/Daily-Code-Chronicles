# 1306. Jump Game III

## Problem Statement
Given an array of non-negative integers `arr`, you are initially positioned at index `start`.

When at index `i`, you can jump to:

- `i + arr[i]`
- `i - arr[i]`

Return `true` if you can reach any index with value `0`, otherwise return `false`.

---

## Approach

Use **Depth First Search (DFS)** with visited marking.

At every index:

1. Check whether current index is out of bounds.
2. Check if index was already visited.
3. If value equals `0`, return `true`.
4. Explore both possible jumps.
5. Mark visited positions to avoid infinite loops.

---

## Time Complexity

```text
O(n)
```

Each position is visited at most once.

---

## Space Complexity

```text
O(n)
```

Recursion stack / visited tracking.

---

# C++ Solution

```cpp
class Solution {
public:

    bool dfs(vector<int>& arr,int idx){

        if(idx<0 || idx>=arr.size() || arr[idx]<0)
            return false;

        if(arr[idx]==0)
            return true;

        int jump=arr[idx];
        arr[idx]=-arr[idx];

        return dfs(arr,idx+jump) ||
               dfs(arr,idx-jump);
    }

    bool canReach(vector<int>& arr, int start) {

        return dfs(arr,start);

    }
};
```

---

# Python Solution

```python
class Solution:

    def canReach(self, arr, start):

        if start < 0 or start >= len(arr) or arr[start] < 0:
            return False

        if arr[start] == 0:
            return True

        jump = arr[start]
        arr[start] *= -1

        return (
            self.canReach(arr,start+jump)
            or
            self.canReach(arr,start-jump)
        )
```

---

# Java Solution

```java
class Solution {

    public boolean canReach(int[] arr, int start) {

        if(start<0 || start>=arr.length || arr[start]<0)
            return false;

        if(arr[start]==0)
            return true;

        int jump=arr[start];
        arr[start]=-arr[start];

        return canReach(arr,start+jump)
            ||
               canReach(arr,start-jump);
    }
}
```

---

# Go Solution

```go
func canReach(arr []int, start int) bool {

    if start < 0 || start >= len(arr) || arr[start] < 0 {
        return false
    }

    if arr[start] == 0 {
        return true
    }

    jump := arr[start]
    arr[start] = -arr[start]

    return canReach(arr,start+jump) ||
           canReach(arr,start-jump)
}
```

---

# C Solution

```c
bool dfs(int* arr,int size,int idx){

    if(idx<0 || idx>=size || arr[idx]<0)
        return false;

    if(arr[idx]==0)
        return true;

    int jump=arr[idx];
    arr[idx]=-arr[idx];

    return dfs(arr,size,idx+jump)
        ||
           dfs(arr,size,idx-jump);
}

bool canReach(int* arr, int arrSize, int start){

    return dfs(arr,arrSize,start);

}
```

---

## Example

Input:

```text
arr = [4,2,3,0,3,1,2]
start = 5
```

Output:

```text
true
```

Explanation:

```text
5 → 4 → 1 → 3

arr[3] = 0

Hence answer = true
```
