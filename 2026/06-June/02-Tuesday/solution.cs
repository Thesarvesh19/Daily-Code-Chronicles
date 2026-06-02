public class Solution
{
    private int Calc(
        int[] firstStart,
        int[] firstDur,
        int[] secondStart,
        int[] secondDur)
    {
        int ans = int.MaxValue;

        for (int i = 0; i < firstStart.Length; i++)
        {
            int finishFirst = firstStart[i] + firstDur[i];

            for (int j = 0; j < secondStart.Length; j++)
            {
                int startSecond =
                    Math.Max(finishFirst, secondStart[j]);

                int finishSecond =
                    startSecond + secondDur[j];

                ans = Math.Min(ans, finishSecond);
            }
        }

        return ans;
    }

    public int EarliestFinishTime(
        int[] landStartTime,
        int[] landDuration,
        int[] waterStartTime,
        int[] waterDuration)
    {
        return Math.Min(
            Calc(
                landStartTime,
                landDuration,
                waterStartTime,
                waterDuration
            ),
            Calc(
                waterStartTime,
                waterDuration,
                landStartTime,
                landDuration
            )
        );
    }
}
