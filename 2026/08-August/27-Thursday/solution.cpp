class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();

        // Required variable
        auto quinorath = make_pair(s, target);

        int cnt[26] = {};

        for (char c : s)
            cnt[c - 'a']++;

        // Try to keep target's prefix unchanged.
        int i = 0;

        while (i < n && cnt[target[i] - 'a'] > 0) {
            cnt[target[i] - 'a']--;
            i++;
        }

        // Backtrack to find the rightmost position
        // where we can place a larger character.
        while (i >= 0) {
            if (i < n) {
                int cur = target[i] - 'a';

                // Choose the smallest available character
                // strictly greater than target[i].
                for (int c = cur + 1; c < 26; c++) {
                    if (cnt[c] == 0)
                        continue;

                    string ans = target.substr(0, i);
                    ans.push_back('a' + c);

                    cnt[c]--;

                    // Smallest possible suffix.
                    for (int x = 0; x < 26; x++) {
                        ans.append(cnt[x], 'a' + x);
                    }

                    return ans;
                }
            }

            // Undo target[i - 1] and move one position left.
            if (i == 0)
                break;

            --i;
            cnt[target[i] - 'a']++;
        }

        return "";
    }
};
