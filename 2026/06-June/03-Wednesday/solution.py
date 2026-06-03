from bisect import bisect_left

class Solution:
    def earliestFinishTime(self,
                           landStartTime,
                           landDuration,
                           waterStartTime,
                           waterDuration):

        def solve(s1, d1, s2, d2):

            rides = sorted(zip(s2, d2))

            start = [x[0] for x in rides]

            m = len(rides)

            pref = [0] * m
            suf = [0] * m

            pref[0] = rides[0][1]

            for i in range(1, m):
                pref[i] = min(pref[i - 1], rides[i][1])

            suf[-1] = rides[-1][0] + rides[-1][1]

            for i in range(m - 2, -1, -1):
                suf[i] = min(
                    suf[i + 1],
                    rides[i][0] + rides[i][1]
                )

            ans = float("inf")

            for st, dur in zip(s1, d1):

                finish = st + dur

                pos = bisect_left(start, finish)

                if pos:
                    ans = min(ans,
                              finish + pref[pos - 1])

                if pos < m:
                    ans = min(ans,
                              suf[pos])

            return ans

        return min(
            solve(landStartTime, landDuration,
                  waterStartTime, waterDuration),
            solve(waterStartTime, waterDuration,
                  landStartTime, landDuration)
        )
