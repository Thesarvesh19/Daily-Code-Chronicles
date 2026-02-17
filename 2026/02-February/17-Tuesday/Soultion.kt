class Solution {
    fun readBinaryWatch(turnedOn: Int): List<String> {
        val result = mutableListOf<String>()

        for (hour in 0..11) {
            for (minute in 0..59) {
                if (Integer.bitCount(hour) + Integer.bitCount(minute) == turnedOn) {
                    result.add("$hour:${String.format("%02d", minute)}")
                }
            }
        }

        return result
    }
}
