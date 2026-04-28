import "sort"

func minOperations(grid [][]int, x int) int {
    nums := []int{}
 
    for _, row := range grid {
        nums = append(nums, row...)
    }

    sort.Ints(nums)

    base := nums[0] % x
    for _, num := range nums {
        if num%x != base {
            return -1
        }
    }

    median := nums[len(nums)/2]
    ops := 0

    for _, num := range nums {
        if num > median {
            ops += (num - median) / x
        } else {
            ops += (median - num) / x
        }
    }

    return ops
}
