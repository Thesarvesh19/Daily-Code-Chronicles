#include <string>
#include <algorithm>
#include <vector>

class Solution {
public:
    int numberOfSubstrings(std::string s) {
        std::vector<int> lastSeen(3, -1);
        int totalCount = 0;
        
        for (int i = 0; i < s.length(); i++) {
            lastSeen[s[i] - 'a'] = i;
            
            // Add the number of valid substrings ending at index i
            totalCount += 1 + std::min({lastSeen[0], lastSeen[1], lastSeen[2]});
        }
        
        return totalCount;
    }
};
