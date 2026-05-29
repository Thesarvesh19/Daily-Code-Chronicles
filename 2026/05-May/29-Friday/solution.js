var minElement = function(nums) {
    const digitSum = (x) => 
        x.toString().split('').reduce((a, b) => a + Number(b), 0);
    
    return Math.min(...nums.map(digitSum));
};
