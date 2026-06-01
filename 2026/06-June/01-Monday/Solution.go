func minimumCost(cost []int) int {
    sort.Sort(sort.Reverse(sort.IntSlice(cost)))

    ans := 0

    for i := 0; i < len(cost); i++ {
        if i%3 != 2 {
            ans += cost[i]
        }
    }

    return ans
}
