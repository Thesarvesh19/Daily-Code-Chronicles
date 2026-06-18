class Solution {

    /**
     * @param Integer $hour
     * @param Integer $minutes
     * @return Float
     */
    function angleClock($hour, $minutes) {
        $hourAngle = ($hour % 12) * 30 + $minutes * 0.5;
        $minuteAngle = $minutes * 6;

        $diff = abs($hourAngle - $minuteAngle);

        return min($diff, 360 - $diff);
    }
}
