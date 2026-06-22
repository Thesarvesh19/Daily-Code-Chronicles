# LeetCode 1189: Maximum Number of Balloons 🎈

**Difficulty:** `Easy`  
**Tags:** `Hash Table`, `String`, `Counting`

## 📝 Problem Statement
Given a string `text`, you want to use the characters of `text` to form as many instances of the word **"balloon"** as possible. 

You can use each character in `text` at **at most once**. Return the maximum number of instances that can be formed.

**Example 1:**
> **Input:** `text = "nlaebolko"`  
> **Output:** `1`

**Example 2:**
> **Input:** `text = "loonbalxballpoon"`  
> **Output:** `2`

**Example 3:**
> **Input:** `text = "leetcode"`  
> **Output:** `0`

---

## 💡 Intuition & Real-Life Analogy

Aise samjho ki tumhare paas ek bada sa dabba hai jismein bahut saare random alphabet blocks bhare hue hain (tumhari `text` string). Tumhara task hai in blocks ko use karke zyada se zyada baar **"balloon"** word banana. 

Ek "balloon" banane ke liye humari exact "recipe" aisi dikhti hai:
* **1x** `b`
* **1x** `a`
* **2x** `l`
* **2x** `o`
* **1x** `n`

Maan lo tumhare dabbe mein 100 `b`, 100 `a`, 100 `l`, aur 100 `o` hain, par sirf **2 `n`** hain. Toh tum kitne "balloon" bana paoge? Sirf 2! Kyunki `n` yahan par hamara *bottleneck* ban gaya. 

Bas yahi poori logic hai is problem ki. Humein bas in paanch specific letters ki frequency count karni hai aur dekhna hai ki minimum complete sets kitne ban rahe hain.

---

## 🚀 Approach

1. **Count Frequencies:** Traverse the string and count the occurrences of every character. 
2. **Extract Target Characters:** Look specifically at the counts for `b`, `a`, `l`, `o`, and `n`.
3. **Handle Doubles:** Since the letters `l` and `o` appear **twice** in the word "balloon", we must divide their total frequencies by `2` (using integer division).
4. **Find the Bottleneck:** The maximum number of "balloon" words we can form is strictly limited by the character we have the least of. So, we return the **minimum** value among these adjusted counts.

---

## ⏱️ Complexity Analysis
* **Time Complexity:** **O(N)**, where `N` is the length of the string `text`. Hum poori string ko frequency map/array banane ke liye sirf ek baar traverse karte hain.
* **Space Complexity:** **O(1)**. Hum frequency store karne ke liye ek fixed size ka array (size 26) use kar rahe hain, isliye space constant hai regardless of input size.

---

## 💻 Implementations

### Python 3
```python
class Solution:
    def maxNumberOfBalloons(self, text: str) -> int:
        return min(
            text.count('b'),
            text.count('a'),
            text.count('l') // 2,
            text.count('o') // 2,
            text.count('n')
        )
