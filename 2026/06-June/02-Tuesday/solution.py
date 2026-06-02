class Solution:
    def calc(self, first_start, first_dur, second_start, second_dur):
        ans = float('inf')

        for i in range(len(first_start)):
            finish_first = first_start[i] + first_dur[i]

            for j in range(len(second_start)):
                start_second = max(finish_first, second_start[j])
                finish_second = start_second + second_dur[j]

                ans = min(ans, finish_second)

        return ans

    def earliestFinishTime(self, landStartTime, landDuration,
                           waterStartTime, waterDuration):

        return min(
            self.calc(
                landStartTime,
                landDuration,
                waterStartTime,
                waterDuration
            ),
            self.calc(
                waterStartTime,
                waterDuration,
                landStartTime,
                landDuration
            )
        )
