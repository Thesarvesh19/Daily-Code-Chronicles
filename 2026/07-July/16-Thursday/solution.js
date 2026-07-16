/**
 * @param {number[]} nums
 * @return {bigint}
 */
var gcdSum = function (nums) {
    const gcd = (a, b) => {
        while (b !== 0) {
            const t = a % b;
            a = b;
            b = t;
        }
        return a;
    };

    const transformed = [];
    let currentMax = 0;

    for (const value of nums) {
        currentMax = Math.max(currentMax, value);
        transformed.push(gcd(value, currentMax));
    }

    transformed.sort((a, b) => a - b);

    let answer = 0n;

    let left = 0;
    let right = transformed.length - 1;

    while (left < right) {
        answer += BigInt(gcd(transformed[left], transformed[right]));
        left++;
        right--;
    }

    return answer;
};
