package heap

import java.util.*


/**
 * https://leetcode.com/problems/minimum-number-of-refueling-stops/
 * */

fun minRefuelStops(target: Int, startFuel: Int, stations: Array<IntArray>): Int {
    val maxHeap = PriorityQueue<Int>(Collections.reverseOrder())
    var i = 0
    var res = 0
    var curr = startFuel
    while (curr < target) {
        while (i < stations.size && curr >= stations[i][0])
            maxHeap.add(stations[i++][1])
        if (maxHeap.isEmpty()) return -1
        curr += maxHeap.poll()
        res++
    }
    return res
}
