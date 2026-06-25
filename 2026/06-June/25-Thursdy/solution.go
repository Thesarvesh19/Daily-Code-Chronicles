func countMajoritySubarrays(nums []int, target int) int {
    n := len(nums)
    ans := 0
    
    for i := 0; i < n; i++ {
        cnt := 0
        for j := i; j < n; j++ {
            if nums[j] == target {
                cnt++
            }
            if cnt * 2 > (j - i + 1) {
                ans++
            }
        }
    }
    return ans
}
