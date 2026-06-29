public class Solution {
    public int NumOfStrings(string[] patterns, string word) {
        int count = 0;
        foreach (string p in patterns) {
            if (word.Contains(p)) {
                count++;
            }
        }
        return count;
    }
}
