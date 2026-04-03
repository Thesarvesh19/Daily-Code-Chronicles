//updated
import java.util.*

class Solution {
    private lateinit var dp: Array<IntArray?>
    private lateinit var robotData: Array<IntArray>
    private lateinit var walls: IntArray
    private var n = 0

    fun maxWalls(robots: IntArray, distance: IntArray, walls: IntArray): Int {
        n = robots.size

        robotData = Array(n) { IntArray(2) }
        for (i in 0 until n) {
            robotData[i][0] = robots[i]
            robotData[i][1] = distance[i]
        }

        robotData.sortBy { it[0] }
        walls.sort()
        this.walls = walls

        dp = Array(n) { IntArray(2) { -1 } }

        return dfs(n - 1, 1)
    }

    private fun dfs(i: Int, nextRight: Int): Int {
        if (i < 0) return 0

        if (dp[i][nextRight] != -1) return dp[i][nextRight]

        val pos = robotData[i][0]
        val dist = robotData[i][1]

        var leftBoundary = pos - dist
        if (i > 0) {
            leftBoundary = maxOf(leftBoundary, robotData[i - 1][0] + 1)
        }

        var l = lowerBound(walls, leftBoundary)
        var r = lowerBound(walls, pos + 1)
        val resLeft = dfs(i - 1, 0) + (r - l)

        var rightBoundary = pos + dist
        if (i + 1 < n) {
            val nextPos = robotData[i + 1][0]
            val nextDist = robotData[i + 1][1]

            rightBoundary = if (nextRight == 0) {
                minOf(rightBoundary, nextPos - nextDist - 1)
            } else {
                minOf(rightBoundary, nextPos - 1)
            }
        }

        val resRight = if (rightBoundary < pos) {
            dfs(i - 1, 1)
        } else {
            l = lowerBound(walls, pos)
            r = lowerBound(walls, rightBoundary + 1)
            dfs(i - 1, 1) + (r - l)
        }

        dp[i][nextRight] = resLeft.coerceAtLeast(resRight)
        return dp[i][nextRight]
    }

    private fun lowerBound(arr: IntArray, target: Int): Int {
        var l = 0
        var r = arr.size
        while (l < r) {
            val m = (l + r) / 2
            if (arr[m] < target) l = m + 1 else r = m
        }
        return l
    }
}
