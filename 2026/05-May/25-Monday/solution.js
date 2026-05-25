var canReach = function(s, minJump, maxJump) {

    let n = s.length;
    let dp = Array(n).fill(false);

    dp[0] = true;
    let reachable = 0;

    for(let i=1;i<n;i++){

        if(i >= minJump)
            reachable += dp[i-minJump];

        if(i > maxJump)
            reachable -= dp[i-maxJump-1];

        dp[i] =
            reachable > 0 &&
            s[i] === '0';
    }

    return dp[n-1];
};
