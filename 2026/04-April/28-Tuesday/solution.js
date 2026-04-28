var minOperations = function(grid, x) {
    let nums = [];

    for (let row of grid) {
        nums.push(...row);
    }

    nums.sort((a, b) => a - b); 

    let base = nums[0] % x;
    for (let num of nums) {
        if (num % x !== base) return -1;
    }

    let median = nums[Math.floor(nums.length / 2)];
    let ops = 0;

    for (let num of nums) {
        ops += Math.floor(Math.abs(num - median) / x);
    }

    return ops;
};
