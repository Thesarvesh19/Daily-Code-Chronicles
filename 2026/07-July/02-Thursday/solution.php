class Solution {
    /**
     * @param Integer[][] $grid
     * @param Integer $health
     * @return Boolean
     */
    function findSafeWalk($grid, $health) {
        $m = count($grid);
        $n = count($grid[0]);
        $dist = array_fill(0, $m, array_fill(0, $n, PHP_INT_MAX));
        $dirs = [[0, 1], [1, 0], [0, -1], [-1, 0]];
        
        $deque = new SplDoublyLinkedList();
        
        $dist[0][0] = $grid[0][0];
        $deque->unshift([0, 0]);
        
        while (!$deque->isEmpty()) {
            $curr = $deque->shift();
            $r = $curr[0];
            $c = $curr[1];
            
            if ($r == $m - 1 && $c == $n - 1) {
                return $health - $dist[$r][$c] > 0;
            }
            
            foreach ($dirs as $d) {
                $nr = $r + $d[0];
                $nc = $c + $d[1];
                if ($nr >= 0 && $nr < $m && $nc >= 0 && $nc < $n) {
                    $w = $grid[$nr][$nc];
                    if ($dist[$r][$c] + $w < $dist[$nr][$nc]) {
                        $dist[$nr][$nc] = $dist[$r][$c] + $w;
                        if ($w == 0) $deque->unshift([$nr, $nc]);
                        else $deque->push([$nr, $nc]);
                    }
                }
            }
        }
        return false;
    }
}
