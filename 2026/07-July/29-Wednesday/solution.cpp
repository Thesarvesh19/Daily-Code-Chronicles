class Solution {
public:
    static constexpr int MAX = 1000001;

    string smallestPalindrome(string s, int k) {
        vector<int> freq(26, 0);

        for (char c : s)
            freq[c - 'a']++;

        vector<int> half(26, 0);
        string mid;

        for (int i = 0; i < 26; i++) {
            half[i] = freq[i] / 2;
            if (freq[i] & 1)
                mid.push_back(char('a' + i));
        }

        if (countWays(half) < k)
            return "";

        string left;
        int halfLen = accumulate(half.begin(), half.end(), 0);

        for (int pos = 0; pos < halfLen; pos++) {
            for (int i = 0; i < 26; i++) {
                if (half[i] == 0)
                    continue;

                half[i]--;
                int ways = countWays(half);

                if (ways >= k) {
                    left.push_back(char('a' + i));
                    break;
                }

                k -= ways;
                half[i]++;
            }
        }

        string right = left;
        reverse(right.begin(), right.end());

        return left + mid + right;
    }

private:
    int countWays(const vector<int>& cnt) {
        int total = accumulate(cnt.begin(), cnt.end(), 0);
        long long res = 1;

        for (int f : cnt) {
            res *= nCk(total, f);
            if (res >= MAX)
                return MAX;
            total -= f;
        }

        return (int)res;
    }

    long long nCk(int n, int k) {
        k = min(k, n - k);
        long long res = 1;

        for (int i = 1; i <= k; i++) {
            res = res * (n - i + 1) / i;
            if (res >= MAX)
                return MAX;
        }

        return res;
    }
};
