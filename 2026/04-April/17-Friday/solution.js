// Minimum Absolute Distance Between Mirror Pairs

var minMirrorPairDistance = function(nums) {
    const map = new Map();
    let ans = Infinity;

    const reverse = (x) => {
        let rev = 0;
        while (x > 0) {
            rev = rev * 10 + (x % 10);
            x = Math.floor(x / 10);
        }
        return rev;
    };

    for (let j = 0; j < nums.length; j++) {
        const num = nums[j];

        if (map.has(num)) {
            ans = Math.min(ans, j - map.get(num));
        }

        const rev = reverse(num);
        map.set(rev, j);
    }

    return ans === Infinity ? -1 : ans;
};
