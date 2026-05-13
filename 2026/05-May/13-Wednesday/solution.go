func minMoves(nums []int, limit int) int {
    n := len(nums)
    diff := make([]int, 2*limit+2)

    for i := 0; i < n/2; i++ {
        a := nums[i]
        b := nums[n-1-i]

        low := min(a, b)
        high := max(a, b)
        sum := a + b

        diff[2] += 2
        diff[low+1] -= 1
        diff[sum] -= 1
        diff[sum+1] += 1
        diff[high+limit+1] += 1
    }

    ans := int(^uint(0) >> 1)
    curr := 0

    for s := 2; s <= 2*limit; s++ {
        curr += diff[s]
        if curr < ans {
            ans = curr
        }
    }

    return ans
}

func min(a, b int) int {
    if a < b {
        return a
    }
    return b
}

func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}
