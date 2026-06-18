public class Solution {
    public double AngleClock(int hour, int minutes) {
        double hourAngle = (hour % 12) * 30.0 + minutes * 0.5;
        double minuteAngle = minutes * 6.0;

        double diff = Math.Abs(hourAngle - minuteAngle);

        return Math.Min(diff, 360.0 - diff);
    }
}
