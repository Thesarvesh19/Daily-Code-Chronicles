function countMajoritySubarrays(nums: number[], target: number): number {
    const n = nums.length;
    let ans = 0;
    
    for (let i = 0; i < n; ++i) {
        let cnt = 0;
        for (let j = i; j < n; ++j) {
            if (nums[j] === target) {
                cnt++;
            }
            const length = j - i + 1;
            if (cnt * 2 > length) {
                ans++;
            }
        }
    }
    return ans;
}
