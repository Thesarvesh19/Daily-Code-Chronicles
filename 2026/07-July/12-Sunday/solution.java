class Solution {
    public int[] arrayRankTransform(int[] arr) {
        int[] sorted = arr.clone();
        Arrays.sort(sorted);

        HashMap<Integer, Integer> rank = new HashMap<>();

        for (int x : sorted) {
            rank.putIfAbsent(x, rank.size() + 1);
        }

        int[] ans = new int[arr.length];
        for (int i = 0; i < arr.length; i++) {
            ans[i] = rank.get(arr[i]);
        }

        return ans;
    }
}
