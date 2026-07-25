func maxProduct(n int) int {
	largest, second := 0, 0

	for n > 0 {
		digit := n % 10
		n /= 10

		if digit >= largest {
			second = largest
			largest = digit
		} else if digit > second {
			second = digit
		}
	}

	return largest * second
}
