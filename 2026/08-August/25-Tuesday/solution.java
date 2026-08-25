class Solution {
    public int missingMultiple(int[] nums, int k) {
        HashSet<Integer> set = new HashSet<>();

        for (int num : nums) {
            set.add(num);
        }

        for (int i = 1; ; i++) {
            int x = i * k;

            if (!set.contains(x)) {
                return x;
            }
        }
    }
}
