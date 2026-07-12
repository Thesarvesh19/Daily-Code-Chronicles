public class Solution {
    public int[] ArrayRankTransform(int[] arr) {
        int[] sorted = (int[])arr.Clone();
        Array.Sort(sorted);

        Dictionary<int, int> rank = new Dictionary<int, int>();

        foreach (int num in sorted) {
            if (!rank.ContainsKey(num))
                rank[num] = rank.Count + 1;
        }

        int[] ans = new int[arr.Length];

        for (int i = 0; i < arr.Length; i++) {
            ans[i] = rank[arr[i]];
        }

        return ans;
    }
}
