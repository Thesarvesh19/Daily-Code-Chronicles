public class Solution
{
    public int[] MaximumWeight(int[][] intervals)
    {
        int n = intervals.Length;

        // {start, end, weight, original index}
        var a = new int[n][];

        for (int i = 0; i < n; i++)
        {
            a[i] = new int[]
            {
                intervals[i][0],
                intervals[i][1],
                intervals[i][2],
                i
            };
        }

        // Sort by start time
        Array.Sort(a, (x, y) =>
        {
            if (x[0] != y[0])
                return x[0].CompareTo(y[0]);

            if (x[1] != y[1])
                return x[1].CompareTo(y[1]);

            return x[3].CompareTo(y[3]);
        });

        int[] starts = new int[n];

        for (int i = 0; i < n; i++)
            starts[i] = a[i][0];

        // Find the first interval whose start > current end.
        int[] next = new int[n];

        for (int i = 0; i < n; i++)
            next[i] = UpperBound(starts, a[i][1]);

        // dp[i, k] stores the best result from i onward
        // when we can still select k intervals.
        State[,] dp = new State[n + 1, 5];
        bool[,] visited = new bool[n + 1, 5];

        State Solve(int i, int k)
        {
            if (i >= n || k == 0)
                return new State(0, new List<int>());

            if (visited[i, k])
                return dp[i, k];

            visited[i, k] = true;

            // Skip current interval
            State skip = Solve(i + 1, k);

            // Take current interval
            State take = Solve(next[i], k - 1);

            take.Score += a[i][2];
            take.Indices.Add(a[i][3]);
            take.Indices.Sort();

            State ans;

            if (take.Score > skip.Score)
            {
                ans = take;
            }
            else if (take.Score < skip.Score)
            {
                ans = skip;
            }
            else
            {
                // Lexicographically smaller indices
                ans = LexicographicallySmaller(take, skip)
                    ? take
                    : skip;
            }

            return dp[i, k] = ans;
        }

        State result = Solve(0, 4);

        return result.Indices.ToArray();
    }

    private int UpperBound(int[] arr, int target)
    {
        int left = 0;
        int right = arr.Length;

        while (left < right)
        {
            int mid = left + (right - left) / 2;

            if (arr[mid] <= target)
                left = mid + 1;
            else
                right = mid;
        }

        return left;
    }

    private bool LexicographicallySmaller(State a, State b)
    {
        int n = Math.Min(a.Indices.Count, b.Indices.Count);

        for (int i = 0; i < n; i++)
        {
            if (a.Indices[i] != b.Indices[i])
                return a.Indices[i] < b.Indices[i];
        }

        return a.Indices.Count < b.Indices.Count;
    }

    private class State
    {
        public long Score;
        public List<int> Indices;

        public State(long score, List<int> indices)
        {
            Score = score;
            Indices = indices;
        }
    }
}
