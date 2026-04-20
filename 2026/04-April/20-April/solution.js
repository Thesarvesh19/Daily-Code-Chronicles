// 2078. Two Furthest Houses With Different Colors
var maxDistance = function(colors) {
    let n = colors.length;
    let ans = 0;

    for (let i = 0; i < n; i++) {
        if (colors[i] !== colors[0]) {
            ans = Math.max(ans, i);
        } 
        if (colors[i] !== colors[n - 1]) {       
            ans = Math.max(ans, n - 1 - i);
        }
    }

    return ans;
};
