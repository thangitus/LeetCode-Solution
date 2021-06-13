package dp


/**
 * https://leetcode.com/problems/minimum-number-of-refueling-stops/
 * */

fun minRefuelStops(target: Int, startFuel: Int, stations: Array<IntArray>): Int {
    val dp = LongArray(stations.size + 1)
    dp[0] = startFuel.toLong()
    for (i in stations.indices)
        for (t in i downTo 0) {
            if (dp[t] < stations[i][0]) break
            dp[t + 1] = Math.max(dp[t + 1], dp[t] + stations[i][1])
        }
    for (i in dp.indices)
        if (dp[i] >= target) return i
    return -1
}
