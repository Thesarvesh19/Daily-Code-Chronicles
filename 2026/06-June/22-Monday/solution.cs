using System;

public class Solution {
    public int MaxNumberOfBalloons(string text) {
        int[] charCounts = new int[26];
        
        // foreach loop is fast and idiomatic in C#
        foreach (char c in text) {
            charCounts[c - 'a']++;
        }
        
        int b = charCounts['b' - 'a'];
        int a = charCounts['a' - 'a'];
        int l = charCounts['l' - 'a'] / 2;
        int o = charCounts['o' - 'a'] / 2;
        int n = charCounts['n' - 'a'];
        
        // Chain Math.Min to find the lowest value
        int min1 = Math.Min(b, a);
        int min2 = Math.Min(l, o);
        int min3 = Math.Min(min1, min2);
        
        return Math.Min(min3, n);
    }
}
