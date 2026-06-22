#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    int maxNumberOfBalloons(std::string text) {
        std::vector<int> charCounts(26, 0);
        
        // Range-based for loop for clean traversal
        for (char c : text) {
            charCounts[c - 'a']++;
        }
        
        int b = charCounts['b' - 'a'];
        int a = charCounts['a' - 'a'];
        int l = charCounts['l' - 'a'] / 2;
        int o = charCounts['o' - 'a'] / 2;
        int n = charCounts['n' - 'a'];
        
        // std::min with an initializer list finds the min of all 5 instantly
        return std::min({b, a, l, o, n});
    }
};
