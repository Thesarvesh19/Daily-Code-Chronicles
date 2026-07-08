/**
 * @param {string} s
 * @param {number[][]} queries
 * @return {number[]}
 */
var sumAndMultiply = function (s, queries) {
    const MOD = 1000000007n;

    const digits = [];
    const positions = [];

    for (let i = 0; i < s.length; i++) {
        if (s[i] !== '0') {
            digits.push(Number(s[i]));
            positions.push(i);
        }
    }

    const m = digits.length;

    if (m === 0) {
        return new Array(queries.length).fill(0);
    }

    const power10 = new Array(m + 1).fill(0n);
    power10[0] = 1n;

    for (let i = 1; i <= m; i++) {
        power10[i] = (power10[i - 1] * 10n) % MOD;
    }

    const prefixValue = new Array(m + 1).fill(0n);
    const prefixSum = new Array(m + 1).fill(0);

    for (let i = 0; i < m; i++) {
        prefixValue[i + 1] =
            (prefixValue[i] * 10n + BigInt(digits[i])) % MOD;

        prefixSum[i + 1] =
            prefixSum[i] + digits[i];
    }

    const first = new Array(s.length + 1).fill(m);

    let idx = m - 1;

    for (let i = s.length - 1; i >= 0; i--) {
        if (idx >= 0 && positions[idx] === i) {
            first[i] = idx;
            idx--;
        } else {
            first[i] = first[i + 1];
        }
    }

    const last = new Array(s.length).fill(-1);

    idx = 0;
    let current = -1;

    for (let i = 0; i < s.length; i++) {
        if (idx < m && positions[idx] === i) {
            current = idx;
            idx++;
        }
        last[i] = current;
    }

    const answer = [];

    for (const [l, r] of queries) {
        const left = first[l];
        const right = last[r];

        if (left > right || left === m || right === -1) {
            answer.push(0);
            continue;
        }

        const len = right - left + 1;

        let number =
            (prefixValue[right + 1] -
                (prefixValue[left] * power10[len]) % MOD +
                MOD) % MOD;

        const digitSum =
            prefixSum[right + 1] - prefixSum[left];

        answer.push(Number((number * BigInt(digitSum)) % MOD));
    }

    return answer;
};
