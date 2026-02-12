Longest Balanced Substring I

##  Problem

A substring is called **balanced** if all distinct characters in the substring appear the same number of times.

Given a string `s`, return the length of the longest balanced substring.

### Constraints
- 1 <= s.length <= 1000
- s consists of lowercase English letters

---

##  Approach

We use a **brute-force with frequency tracking** approach.

### Key Idea

For every starting index:
- Maintain a frequency array of size 26
- Expand substring one character at a time
- Track:
  - `distinct` → number of unique characters
  - `maxFreq` → maximum frequency of any character

A substring is balanced when:

length == distinct * maxFreq


Why?

If all distinct characters appear the same number of times,
and each appears `maxFreq` times, then:

Total length = distinct × maxFreq


---

##  Complexity

- **Time Complexity:** O(n²)
- **Space Complexity:** O(1) (fixed 26 letters)

---

##  Why This Works

Since the maximum string length is 1000, checking all substrings (O(n²))
is efficient enough.

The frequency array ensures constant-time character updates.

---

##  Example

Input:
s = "abbac"


Output:
4


Explanation:
"abba" is balanced since both 'a' and 'b' appear twice.
