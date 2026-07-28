#include <string>
#include <algorithm>

class Solution {
public:
    std::string smallestPalindrome(std::string s) {
        int n = s.length();
        
        // Extract the first half
        std::string half = s.substr(0, n / 2);
        
        // Sort the first half lexicographically
        std::sort(half.begin(), half.end());
        
        // Reconstruct the mirrored string
        std::string result = half;
        if (n % 2 != 0) {
            result += s[n / 2]; // Add middle character if length is odd
        }
        
        // Reverse and append the half
        std::string right_half = half;
        std::reverse(right_half.begin(), right_half.end());
        result += right_half;
        
        return result;
    }
};
