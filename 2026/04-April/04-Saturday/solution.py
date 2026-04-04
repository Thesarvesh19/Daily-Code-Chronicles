#updated
class Solution:
    def decodeCiphertext(self, encodedText, rows):
        if rows == 1:
            return encodedText
        
        n = len(encodedText)
        cols = n // rows
        
        matrix = []
        index = 0
        for i in range(rows):
            matrix.append(list(encodedText[index:index + cols]))
            index += cols
        
        res = []
        for start in range(cols):
            i, j = 0, start
            while i < rows and j < cols:
                res.append(matrix[i][j])
                i += 1
                j += 1
        
        return "".join(res).rstrip()
