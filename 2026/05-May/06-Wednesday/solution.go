func rotateTheBox(boxGrid [][]byte) [][]byte {

    m := len(boxGrid) 
    n := len(boxGrid[0]) 

    for i := 0; i < m; i++ {

        emptyPos := n - 1

        for j := n - 1; j >= 0; j-- {

            if boxGrid[i][j] == '*' {
                emptyPos = j - 1
            }

            else if boxGrid[i][j] == '#' {

                boxGrid[i][j], boxGrid[i][emptyPos] =
                    boxGrid[i][emptyPos], boxGrid[i][j]

                emptyPos--
            }
        }
    }

    ans := make([][]byte, n)

    for i := range ans {
        ans[i] = make([]byte, m)
    }

    for i := 0; i < m; i++ {
        for j := 0; j < n; j++ {
            ans[j][m-1-i] = boxGrid[i][j]
        }
    }

    return ans
}
