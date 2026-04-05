var judgeCircle = function(moves) {
    let x = 0, y = 0;
    
    for (let move of moves) {
        if (move === 'U') y++;
        else if (move === 'D') y--; 
        else if (move === 'R') x++;
        else if (move === 'L') x--;
    }
    
    return x === 0 && y === 0;
};
