var arrayRankTransform = function(arr) {
    const sorted = [...new Set(arr)].sort((a, b) => a - b);

    const rank = new Map();

    sorted.forEach((num, idx) => {
        rank.set(num, idx + 1);
    });

    return arr.map(num => rank.get(num));
};
