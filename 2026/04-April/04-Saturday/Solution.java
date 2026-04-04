//update
class Solution {
    public String decodeCiphertext(String encodedText, int rows) {
        if (rows == 1) return encodedText;

        int n = encodedText.length();
        int cols = n / rows;

        char[][] matrix = new char[rows][cols];
        int idx = 0;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                matrix[i][j] = encodedText.charAt(idx++);
            }
        }

        StringBuilder res = new StringBuilder();

        for (int start = 0; start < cols; start++) {
            int i = 0, j = start;
            while (i < rows && j < cols) {
                res.append(matrix[i][j]);
                i++;
                j++;
            }
        }

        return res.toString().replaceAll("\\s+$", "");
    }
}
