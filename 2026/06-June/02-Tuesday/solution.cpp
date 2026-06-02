class Solution {
public:
    int calc(vector<int>& firstStart, vector<int>& firstDur,
             vector<int>& secondStart, vector<int>& secondDur) {

        int ans = INT_MAX;

        for (int i = 0; i < firstStart.size(); i++) {
            int finishFirst = firstStart[i] + firstDur[i];

            for (int j = 0; j < secondStart.size(); j++) {
                int startSecond = max(finishFirst, secondStart[j]);
                int finishSecond = startSecond + secondDur[j];

                ans = min(ans, finishSecond);
            }
        }

        return ans;
    }

    int earliestFinishTime(vector<int>& landStartTime,
                           vector<int>& landDuration,
                           vector<int>& waterStartTime,
                           vector<int>& waterDuration) {

        return min(
            calc(landStartTime, landDuration,
                 waterStartTime, waterDuration),

            calc(waterStartTime, waterDuration,
                 landStartTime, landDuration)
        );
    }
};
