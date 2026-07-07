/**
 * @param {number} n
 * @return {number}
 */
var sumAndMultiply = function (n) {
    const digits = [];

    while (n > 0) {
        const d = n % 10;
        if (d !== 0)
            digits.push(d);
        n = Math.floor(n / 10);
    }

    digits.reverse();

    let value = 0;
    let sum = 0;

    for (const d of digits) {
        value = value * 10 + d;
        sum += d;
    }

    return value * sum;
};
