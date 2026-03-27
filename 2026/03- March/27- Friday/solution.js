//updated 
class Solution {
    areSimilar(mat, k) {
        const m = mat.length;
        const n = mat[0].length;

        const shift = k % n;

        if (shift === 0) return true;

        for (let i = 0; i < m; i++) {
            const row = mat[i];
            let shifted;

            if (i % 2 === 0) {
                // left shift
                shifted = row.slice(shift).concat(row.slice(0, shift));
            } else {
                // right shift
                shifted = row.slice(-shift).concat(row.slice(0, -shift));
            }

            if (shifted.toString() !== row.toString()) {
                return false;
            }
        }

        return true;
    }
}

module.exports = Solution;
