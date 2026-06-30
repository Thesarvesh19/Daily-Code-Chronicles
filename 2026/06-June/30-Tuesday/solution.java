import java.util.Arrays;

class Solution {
    public int numberOfSubstrings(String s) {
        int[] lastSeen = new int[]{-1, -1, -1};
        int totalCount = 0;
        
        for (int i = 0; i < s.length(); i++) {
            lastSeen[s.charAt(i) - 'a'] = i;
            
            // Find the minimum index among 'a', 'b', and 'c'
            int minIndex = Math.min(lastSeen[0], Math.min(lastSeen[1], lastSeen[2]));
            
            totalCount += minIndex + 1;
        }
        
        return totalCount;
    }
}
