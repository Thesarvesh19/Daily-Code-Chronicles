using System;

public class Solution {
    public string SmallestPalindrome(string s) {
        int n = s.Length;
        int halfLen = n / 2;

        // Extract and sort the first half
        char[] half = s.Substring(0, halfLen).ToCharArray();
        Array.Sort(half);

        string leftHalf = new string(half);
        string middle = (n % 2 != 0) ? s[halfLen].ToString() : "";

        // Reverse the sorted half to get the right side
        Array.Reverse(half);
        string rightHalf = new string(half);

        return leftHalf + middle + rightHalf;
    }
}
