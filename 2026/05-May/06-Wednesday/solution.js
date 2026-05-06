var rotateTheBox = function(boxGrid) {

    let m = boxGrid.length;
    let n = boxGrid[0].length;

    for (let i = 0; i < m; i++) {
 
        let emptyPos = n - 1; 

        for (let j = n - 1; j >= 0; j--) {

            if (boxGrid[i][j] === '*') {
                emptyPos = j - 1;
            }

            else if (boxGrid[i][j] === '#') {

                [boxGrid[i][j], boxGrid[i][emptyPos]] =
                [boxGrid[i][emptyPos], boxGrid[i][j]];

                emptyPos--;
            }
        }
    }

    let ans = Array.from({ length: n }, () => Array(m));

    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            ans[j][m - 1 - i] = boxGrid[i][j];
        }
    }

    return ans;
};
