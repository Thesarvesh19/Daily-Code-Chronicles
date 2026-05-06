public class Solution {

    public char[][] RotateTheBox(char[][] boxGrid) {

        int m = boxGrid.Length;
        int n = boxGrid[0].Length;

        for (int i = 0; i < m; i++) {

            int emptyPos = n - 1;

            for (int j = n - 1; j >= 0; j--) {

                if (boxGrid[i][j] == '*') {
                    emptyPos = j - 1;
                }

                else if (boxGrid[i][j] == '#') {

                    char temp = boxGrid[i][j];
                    boxGrid[i][j] = boxGrid[i][emptyPos];
                    boxGrid[i][emptyPos] = temp;

                    emptyPos--;
                }
            }
        }

        char[][] ans = new char[n][];

        for (int i = 0; i < n; i++) {
            ans[i] = new char[m];
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ans[j][m - 1 - i] = boxGrid[i][j];
            }
        }

        return ans;
    }
}
