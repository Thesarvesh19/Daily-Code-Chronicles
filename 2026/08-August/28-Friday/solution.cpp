#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.size();
        vector<int> cnt(26, 0);

        for (char c : s)
            cnt[c - 'a']++;

        // A palindrome can have at most one character
        // with an odd frequency.
        int odd = 0;
        char mid = 0;

        for (int i = 0; i < 26; i++) {
            if (cnt[i] % 2) {
                odd++;
                mid = char('a' + i);
            }
        }

        if (odd > 1)
            return "";

        // Counts available for the left half.
        vector<int> half(26);
        for (int i = 0; i < 26; i++)
            half[i] = cnt[i] / 2;

        string left;

        auto buildPalindrome = [&](const string& l) {
            string res = l;

            if (mid)
                res += mid;

            for (int i = (int)l.size() - 1; i >= 0; i--)
                res += l[i];

            return res;
        };

        for (int pos = 0; pos < n / 2; pos++) {

            bool found = false;

            // Try the smallest possible character.
            for (int c = 0; c < 26; c++) {
                if (half[c] == 0)
                    continue;

                half[c]--;
                left.push_back(char('a' + c));

                // Put the largest possible characters
                // in all remaining positions.
                string remaining;

                for (int x = 25; x >= 0; x--) {
                    remaining += string(half[x], char('a' + x));
                }

                string candidateLeft = left + remaining;
                string candidate = buildPalindrome(candidateLeft);

                if (candidate > target) {
                    found = true;
                    break;
                }

                // This character cannot lead to a valid answer.
                left.pop_back();
                half[c]++;
            }

            if (!found)
                return "";
        }

        string ans = buildPalindrome(left);

        return ans > target ? ans : "";
    }
};
