LeetCode 1021: Remove Outermost Parentheses

This repository contains optimal solutions for LeetCode 1021: Remove Outermost Parentheses in both Python and C++.

📋 Problem Description

A valid parentheses string is either empty "", "(" + A + ")", or A + B, where A and B are valid parentheses strings, and + represents string concatenation.

For example, "", "()()", "(())()" are all valid parentheses strings.

A valid parentheses string s is primitive if it is nonempty, and there does not exist a way to split it into s = A + B, with non-empty valid parentheses strings s = A + B.

Given a valid parentheses string s, consider its primitive decomposition: $s = s_1 + s_2 + \dots + s_k$, where $s_i$ are primitive valid parentheses strings.

Return s after removing the outermost parentheses of every primitive string in the primitive decomposition of s.

💡 Approach

To remove the outermost parentheses of each primitive component, we can maintain the nesting depth of the parentheses:

Initialize a counter depth to track the current level of nesting.

Iterate through each character of the string:

If we encounter an opening parenthesis '(':

If depth > 0, it means this is not the outermost parenthesis of the current primitive string, so we append it to our result.

Increment depth.

If we encounter a closing parenthesis ')':

Decrement depth.

If depth > 0, it means this is not the outermost closing parenthesis, so we append it to our result.

Return the reconstructed string.

📂 Solutions

Python 3

class Solution:
    def removeOuterParentheses(self, s: str) -> str:
        res = []
        depth = 0
        
        for char in s:
            if char == '(':
                if depth > 0:
                    res.append(char)
                depth += 1
            else:  # char == ')'
                depth -= 1
                if depth > 0:
                    res.append(char)
                    
        return "".join(res)


C++

#include <string>

class Solution {
public:
    std::string removeOuterParentheses(std::string s) {
        std::string res;
        int depth = 0;
        
        for (char c : s) {
            if (c == '(') {
                if (depth > 0) {
                    res.push_back(c);
                }
                depth++;
            } else { // c == ')'
                depth--;
                if (depth > 0) {
                    res.push_back(c);
                }
            }
        }
        
        return res;
    }
};


⏱️ Complexity Analysis

Time Complexity: $\mathcal{O}(n)$, where $n$ is the length of the string s. Every character is processed in a single pass.

Space Complexity: $\mathcal{O}(1)$ auxiliary space (excluding the space required to store the output result string).
