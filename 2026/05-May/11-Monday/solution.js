var separateDigits = function(nums) {
    let result = [];

    for (let num of nums) {
        let digits = num.toString();

        for (let ch of digits) {
            result.push(parseInt(ch));
        }
    }

    return result;
};
