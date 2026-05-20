func findThePrefixCommonArray(A []int, B []int) []int {
    n := len(A)
    count := make([]int, n+1)
    ans := []int{}
    common := 0

    for i := 0; i < n; i++ {
        count[A[i]]++
        if count[A[i]] == 2 {
            common++
        }

        count[B[i]]++
        if count[B[i]] == 2 {
            common++
        }

        ans = append(ans, common)
    }

    return ans
}
