# 2657. Find the Prefix Common Array of Two Arrays

## Problem Statement

You are given two **0-indexed permutations** `A` and `B` of length `n`.

A **prefix common array** `C` is defined such that:

`C[i]` = number of common elements present in both:

- A[0 ... i]
- B[0 ... i]

Return the prefix common array of A and B.

---

## Example

### Input

```text
A = [1,3,2,4]
B = [3,1,2,4]
```

### Output

```text
[0,2,3,4]
```

### Explanation

Index 0:

Prefix:
A → [1]
B → [3]

Common elements = 0

Result:

```text
C[0] = 0
```

Index 1:

Prefix:
A → [1,3]
B → [3,1]

Common = {1,3}

```text
C[1] = 2
```

Index 2:

Prefix:
A → [1,3,2]
B → [3,1,2]

Common = {1,2,3}

```text
C[2] = 3
```

Final answer:

```text
[0,2,3,4]
```

---

# Approach

We traverse both arrays simultaneously.

Maintain:

- `count[]` → stores frequency of each number
- `common` → number of values appearing in both arrays

Whenever frequency becomes:

```text
count[x] == 2
```

It means:

- One occurrence from A
- One occurrence from B

Thus increase common count.

Store common count after every index.

---

# Algorithm

1. Initialize:

```text
count[n+1]
common = 0
answer = []
```

2. Iterate from `0 → n-1`

3. Update frequency for:

```text
A[i]
B[i]
```

4. If frequency becomes 2:

Increment common count

5. Append common count into answer

6. Return answer

---

# Dry Run

Input:

```text
A = [1,3,2,4]
B = [3,1,2,4]
```

| i | A[i] | B[i] | count changes | Common | Answer |
|---|------|------|---------------|--------|--------|
|0|1|3|1→1,3→1|0|[0]|
|1|3|1|3→2,1→2|2|[0,2]|
|2|2|2|2→2|3|[0,2,3]|
|3|4|4|4→2|4|[0,2,3,4]|

Final:

```text
[0,2,3,4]
```

---

# Complexity Analysis

### Time Complexity

For each element we perform constant operations.

```text
O(n)
```

---

### Space Complexity

Frequency array:

```text
O(n)
```

---

# Solutions

## C++

```cpp
class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {

        int n=A.size();

        vector<int> freq(n+1,0);
        vector<int> ans;

        int common=0;

        for(int i=0;i<n;i++){

            if(++freq[A[i]]==2)
                common++;

            if(++freq[B[i]]==2)
                common++;

            ans.push_back(common);
        }

        return ans;
    }
};
```

---

## Python

```python
class Solution:
    def findThePrefixCommonArray(self, A, B):

        n=len(A)

        freq=[0]*(n+1)
        ans=[]
        common=0

        for i in range(n):

            freq[A[i]]+=1
            if freq[A[i]]==2:
                common+=1

            freq[B[i]]+=1
            if freq[B[i]]==2:
                common+=1

            ans.append(common)

        return ans
```

---

## Java

```java
class Solution {

    public int[] findThePrefixCommonArray(
        int[] A,
        int[] B
    ) {

        int n=A.length;

        int[] freq=new int[n+1];
        int[] ans=new int[n];

        int common=0;

        for(int i=0;i<n;i++){

            if(++freq[A[i]]==2)
                common++;

            if(++freq[B[i]]==2)
                common++;

            ans[i]=common;
        }

        return ans;
    }
}
```

---

## Go

```go
func findThePrefixCommonArray(
    A []int,
    B []int,
) []int {

    n:=len(A)

    freq:=make([]int,n+1)
    ans:=[]int{}

    common:=0

    for i:=0;i<n;i++{

        freq[A[i]]++

        if freq[A[i]]==2{
            common++
        }

        freq[B[i]]++

        if freq[B[i]]==2{
            common++
        }

        ans=append(ans,common)
    }

    return ans
}
