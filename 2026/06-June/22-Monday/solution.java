class Solution {
    public int maxNumberOfBalloons(String text) {
        int[] charCounts = new int[26];
        
        // String ko traverse karke har character ki frequency store kar lo
        for (char c : text.toCharArray()) {
            charCounts[c - 'a']++;
        }
        
        // Ab specifically 'b', 'a', 'l', 'o', 'n' ki frequencies nikalenge
        int b = charCounts['b' - 'a'];
        int a = charCounts['a' - 'a'];
        int l = charCounts['l' - 'a'] / 2; // Divided by 2
        int o = charCounts['o' - 'a'] / 2; // Divided by 2
        int n = charCounts['n' - 'a'];
        
        // Find the minimum bottleneck
        int min = Math.min(b, a);
        min = Math.min(min, l);
        min = Math.min(min, o);
        min = Math.min(min, n);
        
        return min;
    }
}
