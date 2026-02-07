/**
 * Problem:
 * Given a string consisting only of characters 'a' and 'b',
 * determine the minimum number of deletions needed so that
 * all 'a' characters appear before any 'b' characters.
 *
 * In other words, the final string should be in the form:
 * "aaa...bbb..."
 *
 * Approach:
 * - Traverse the string from left to right.
 * - Keep track of how many 'b' characters have been seen so far.
 * - When an 'a' is found after a 'b', there are two choices:
 *   1) Delete this 'a'
 *   2) Delete all previous 'b's
 * - Choose the option with the minimum deletions.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
class Solution {

    public int minimumDeletions(String s) {
        int bCount = 0;      // number of 'b's seen so far
        int deletions = 0;   // minimum deletions needed

        for (char ch : s.toCharArray()) {
            if (ch == 'b') {
                bCount++;
            } else { // ch == 'a'
                deletions = Math.min(deletions + 1, bCount);
            }
        }
        return deletions;
    }
}
