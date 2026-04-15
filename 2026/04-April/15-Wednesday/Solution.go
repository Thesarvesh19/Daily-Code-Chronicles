import "math"

func closestTarget(words []string, target string, startIndex int) int {
    n := len(words)
    ans := math.MaxInt32

    for i := 0; i < n; i++ {
        if words[i] == target {
            d := abs(i - startIndex)
            ans = min(ans, min(d, n-d))
        }
    }

    if ans == math.MaxInt32 {
        return -1
    }
    return ans
}

func abs(x int) int {
    if x < 0 {
        return -x
    }
    return x
}

func min(a, b int) int {
    if a < b {
        return a
    }
    return b
}
