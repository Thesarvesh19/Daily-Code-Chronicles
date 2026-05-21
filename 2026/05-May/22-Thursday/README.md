# 3043. Find the Length of the Longest Common Prefix

## Problem Statement
You are given two arrays of positive integers `arr1` and `arr2`.

A prefix of an integer is obtained by removing some digits from the end of the number.

Return the length of the **longest common prefix** between any integer in `arr1` and any integer in `arr2`.

### Example

Input:
arr1 = [1,10,100]
arr2 = [1000]

Output:
3

Explanation:
- Prefixes of 100 → 1,10,100
- Prefixes of 1000 → 1,10,100,1000

Longest common prefix = 100  
Length = 3

---

## Approach 1: HashSet + Prefix Storage

### Idea
1. Convert each number in `arr1` into string.
2. Store all prefixes in a hash set.
3. Traverse numbers in `arr2`.
4. Generate prefixes and check if present.
5. Keep maximum prefix length.

---

## C++ Solution

```cpp
class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {

        unordered_set<string> st;

        for(int x : arr1){
            string s = to_string(x);
            string pref = "";

            for(char c : s){
                pref += c;
                st.insert(pref);
            }
        }

        int ans = 0;

        for(int x : arr2){
            string s = to_string(x);
            string pref = "";

            for(char c : s){
                pref += c;

                if(st.count(pref))
                    ans = max(ans,(int)pref.size());
            }
        }

        return ans;
    }
};
