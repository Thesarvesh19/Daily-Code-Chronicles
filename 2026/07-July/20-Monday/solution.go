func shiftGrid(grid [][]int, k int) [][]int {
	rows := len(grid)
	cols := len(grid[0])
	total := rows * cols

	k %= total

	result := make([][]int, rows)
	for i := range result {
		result[i] = make([]int, cols)
	}

	for r := 0; r < rows; r++ {
		for c := 0; c < cols; c++ {

			current := r*cols + c
			target := (current + k) % total

			nr := target / cols
			nc := target % cols

			result[nr][nc] = grid[r][c]
		}
	}

	return result
}
