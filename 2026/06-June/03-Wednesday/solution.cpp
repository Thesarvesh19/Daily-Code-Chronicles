class Solution {
public:
    long long earliestFinishTime(vector<int>& landStartTime,
                                 vector<int>& landDuration,
                                 vector<int>& waterStartTime,
                                 vector<int>& waterDuration) {

        auto solve = [&](vector<int>& s1, vector<int>& d1,
                         vector<int>& s2, vector<int>& d2) {

            int m = s2.size();

            vector<pair<long long,long long>> rides;

            for (int i = 0; i < m; i++)
                rides.push_back({s2[i], d2[i]});

            sort(rides.begin(), rides.end());

            vector<long long> start(m);
            vector<long long> prefDur(m);
            vector<long long> sufFinish(m);

            for (int i = 0; i < m; i++)
                start[i] = rides[i].first;

            prefDur[0] = rides[0].second;

            for (int i = 1; i < m; i++)
                prefDur[i] = min(prefDur[i - 1], rides[i].second);

            sufFinish[m - 1] =
                rides[m - 1].first + rides[m - 1].second;

            for (int i = m - 2; i >= 0; i--)
                sufFinish[i] = min(
                    sufFinish[i + 1],
                    rides[i].first + rides[i].second
                );

            long long ans = LLONG_MAX;

            for (int i = 0; i < (int)s1.size(); i++) {

                long long finish1 =
                    (long long)s1[i] + d1[i];

                int pos = lower_bound(
                    start.begin(),
                    start.end(),
                    finish1
                ) - start.begin();

                if (pos > 0)
                    ans = min(ans,
                              finish1 + prefDur[pos - 1]);

                if (pos < m)
                    ans = min(ans,
                              sufFinish[pos]);
            }

            return ans;
        };

        return min(
            solve(landStartTime, landDuration,
                  waterStartTime, waterDuration),
            solve(waterStartTime, waterDuration,
                  landStartTime, landDuration)
        );
    }
};
