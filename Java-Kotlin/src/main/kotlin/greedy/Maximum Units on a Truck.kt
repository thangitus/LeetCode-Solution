package greedy

/**
 * https://leetcode.com/problems/maximum-units-on-a-truck/
 * */

fun maximumUnits(boxTypes: Array<IntArray>, truckSize: Int): Int {
    boxTypes.sortByDescending { it[1] }
    var ans = 0
    var size = truckSize
    for (i in boxTypes.indices) {
        ans += if (size >= boxTypes[i][0])
            boxTypes[i][0] * boxTypes[i][1]
        else size * boxTypes[i][1]
        size -= boxTypes[i][0]
        if (size <= 0) break
    }
    return ans
}
