// 2078. Two Furthest Houses With Different Colors
func maxDistance(colors []int) int {
    n := len(colors)
    ans := 0

    for i := 0; i < n; i++ {
        if colors[i] != colors[0] {
            if i > ans {
                ans = i
            }
        }
        if colors[i] != colors[n-1] {
            if n-1-i > ans {
                ans = n-1-i
            }
        }
    }
 
    return ans
}
