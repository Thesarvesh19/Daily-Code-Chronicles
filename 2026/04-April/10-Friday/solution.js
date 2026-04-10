var minimumDistance = function(nums) {
    let map = new Map();

    for (let i = 0; i < nums.length; i++) {
        if (!map.has(nums[i])) map.set(nums[i], []);
        map.get(nums[i]).push(i);
    }

    let ans = Infinity;

    for (let arr of map.values()) {
        for (let i = 0; i + 2 < arr.length; i++) {
            ans = Math.min(ans, 2 * (arr[i+2] - arr[i]));
        }
    }

    return ans === Infinity ? -1 : ans;
};
