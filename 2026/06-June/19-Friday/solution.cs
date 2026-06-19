public class Solution {
    public int LargestAltitude(int[] gain) {
        int altitude = 0;
        int highest = 0;

        foreach (int g in gain) {
            altitude += g;
            highest = Math.Max(highest, altitude);
        }

        return highest;
    }
}
