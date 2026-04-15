var closestTarget = function(words, target, startIndex) {
    let n = words.length;
    let ans = Infinity;

    for (let i = 0; i < n; i++) {
        if (words[i] === target) {
            let d = Math.abs(i - startIndex);
            ans = Math.min(ans, Math.min(d, n - d));
        }
    } 

    return ans === Infinity ? -1 : ans;
};
