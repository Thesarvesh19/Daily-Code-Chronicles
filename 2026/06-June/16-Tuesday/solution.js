var processStr = function(s) {
    let res = [];

    for (const ch of s) {
        if (ch >= 'a' && ch <= 'z') {
            res.push(ch);
        } else if (ch === '*') {
            if (res.length) res.pop();
        } else if (ch === '#') {
            res.push(...res);
        } else { // '%'
            res.reverse();
        }
    }

    return res.join('');
};
