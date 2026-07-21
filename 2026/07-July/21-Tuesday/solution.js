/**
 * @param {string} s
 * @return {number}
 */
var maxActiveSectionsAfterTrade = function (s) {
    let ones = 0;
    let prevZero = 0;
    let best = 0;
    let i = 0;

    while (i < s.length) {
        let j = i;
        while (j < s.length && s[j] === s[i]) {
            j++;
        }

        const len = j - i;

        if (s[i] === '1') {
            ones += len;
        } else {
            best = Math.max(best, prevZero + len);
            prevZero = len;
        }

        i = j;
    }

    return ones + best;
};
