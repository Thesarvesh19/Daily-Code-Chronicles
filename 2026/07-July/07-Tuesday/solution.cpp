class Solution {
public:
    long long sumAndMultiply(int n) {
        vector<int> digits;

        while (n > 0) {
            int d = n % 10;
            if (d != 0)
                digits.push_back(d);
            n /= 10;
        }

        reverse(digits.begin(), digits.end());

        long long value = 0;
        int sum = 0;

        for (int d : digits) {
            value = value * 10 + d;
            sum += d;
        }

        return value * sum;
    }
};
