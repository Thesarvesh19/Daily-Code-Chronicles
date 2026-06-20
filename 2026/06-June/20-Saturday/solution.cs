public class Solution {
    public int MaxBuilding(int n, int[][] restrictions) {
        var list = restrictions
            .Select(r => new int[] { r[0], r[1] })
            .ToList();

        list.Add(new int[] { 1, 0 });

        if (!list.Any(r => r[0] == n))
            list.Add(new int[] { n, n - 1 });

        list.Sort((a, b) => a[0].CompareTo(b[0]));

        int m = list.Count;

        for (int i = 1; i < m; i++) {
            list[i][1] = Math.Min(
                list[i][1],
                list[i - 1][1] + list[i][0] - list[i - 1][0]
            );
        }

        for (int i = m - 2; i >= 0; i--) {
            list[i][1] = Math.Min(
                list[i][1],
                list[i + 1][1] + list[i + 1][0] - list[i][0]
            );
        }

        int ans = 0;

        for (int i = 1; i < m; i++) {
            ans = Math.Max(
                ans,
                (list[i - 1][1] + list[i][1] +
                list[i][0] - list[i - 1][0]) / 2
            );
        }

        return ans;
    }
}
