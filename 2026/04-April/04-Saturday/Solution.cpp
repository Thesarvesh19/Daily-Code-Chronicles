//update
class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        if (rows == 1) return encodedText;

        int n = encodedText.size();
        int cols = n / rows;

        vector<vector<char>> matrix(rows, vector<char>(cols));
        int idx = 0;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                matrix[i][j] = encodedText[idx++];
            }
        }

        string res;

        for (int start = 0; start < cols; start++) {
            int i = 0, j = start;
            while (i < rows && j < cols) {
                res += matrix[i][j];
                i++;
                j++;
            }
        }

        while (!res.empty() && res.back() == ' ') res.pop_back();

        return res;
    }
};
