class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();
        int half = n / 2;

        int leftSum = 0, rightSum = 0;
        int leftQ = 0, rightQ = 0;

        for (int i = 0; i < half; i++) {
            if (num[i] == '?')
                leftQ++;
            else
                leftSum += num[i] - '0';
        }

        for (int i = half; i < n; i++) {
            if (num[i] == '?')
                rightQ++;
            else
                rightSum += num[i] - '0';
        }

        // If the number of ? is odd, Alice can always win.
        if ((leftQ + rightQ) % 2 == 1)
            return true;

        // Difference between the fixed sums.
        int diff = leftSum - rightSum;

        // Alice wins if the required adjustment cannot be balanced.
        return diff != 9 * (rightQ - leftQ) / 2;
    }
};
