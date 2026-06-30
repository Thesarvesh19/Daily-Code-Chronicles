/**
 * @param {string} s
 * @return {number}
 */
var numberOfSubstrings = function(s) {
    const lastSeen = { 'a': -1, 'b': -1, 'c': -1 };
    let totalCount = 0;
    
    for (let i = 0; i < s.length; i++) {
        lastSeen[s[i]] = i;
        
        // Accumulate valid starting positions
        totalCount += Math.min(lastSeen['a'], lastSeen['b'], lastSeen['c']) + 1;
    }
    
    return totalCount;
};
