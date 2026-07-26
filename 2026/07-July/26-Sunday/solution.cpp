#include <vector>
#include <queue>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    string rearrangeString(string s, int k) {
        if (k <= 1)
            return s;

        unordered_map<char, int> freq;
        for (char c : s)
            ++freq[c];

        priority_queue<pair<int, char>> maxHeap;
        for (auto& [ch, count] : freq)
            maxHeap.push({count, ch});

        queue<pair<int, char>> waitQueue;
        string result;

        while (!maxHeap.empty()) {
            auto [count, ch] = maxHeap.top();
            maxHeap.pop();

            result += ch;
            --count;

            waitQueue.push({count, ch});

            if (waitQueue.size() >= k) {
                auto [cnt, c] = waitQueue.front();
                waitQueue.pop();
                if (cnt > 0)
                    maxHeap.push({cnt, c});
            }
        }

        return result.size() == s.size() ? result : "";
    }
};
