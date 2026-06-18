class Solution {
    fun angleClock(hour: Int, minutes: Int): Double {
        val hourAngle = (hour % 12) * 30.0 + minutes * 0.5
        val minuteAngle = minutes * 6.0

        val diff = kotlin.math.abs(hourAngle - minuteAngle)

        return minOf(diff, 360.0 - diff)
    }
}
