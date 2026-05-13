var minMoves = function(nums, limit) {
    const n = nums.length;
    const diff = new Array(2 * limit + 2).fill(0);

    for (let i = 0; i < n / 2; i++) {
        let a = nums[i];
        let b = nums[n - 1 - i];

        let low = Math.min(a, b);
        let high = Math.max(a, b);
        let sum = a + b;

        diff[2] += 2;
        diff[low + 1] -= 1;
        diff[sum] -= 1;
        diff[sum + 1] += 1;
        diff[high + limit + 1] += 1;
    }

    let answer = Infinity;
    let current = 0;

    for (let s = 2; s <= 2 * limit; s++) {
        current += diff[s];
        answer = Math.min(answer, current);
    }

    return answer;
};
