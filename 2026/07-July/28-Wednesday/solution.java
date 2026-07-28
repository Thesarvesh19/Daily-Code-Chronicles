import java.util.Arrays;

class Solution {
    public String smallestPalindrome(String s) {
        int n = s.length();
        int halfLen = n / 2;

        // Extract the first half and sort its characters
        char[] half = s.substring(0, halfLen).toCharArray();
        Arrays.sort(half);

        String leftHalf = new String(half);
        String middle = (n % 2 != 0) ? String.valueOf(s.charAt(halfLen)) : "";

        // Reverse the sorted half for the right side
        StringBuilder sb = new StringBuilder(leftHalf);
        String rightHalf = sb.reverse().toString();

        return leftHalf + middle + rightHalf;
    }
}
