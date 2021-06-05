package heap

import java.util.*


/**
 * https://leetcode.com/problems/maximum-performance-of-a-team/
 * */

fun maxPerformance(n: Int, speed: IntArray, efficiency: IntArray, k: Int): Int {
    val engineers = Array(n) { IntArray(2) }
    for (i in 0 until n) {
        engineers[i][0] = efficiency[i]
        engineers[i][1] = speed[i]
    }
    engineers.sortWith(compareBy<IntArray> { it[0] }.reversed())
    val heap = PriorityQueue<Int>()
    var ans: Long = 0
    var curSum = 0
    engineers.forEach {
        curSum += it[1]
        heap.add(it[1])
        if (heap.size > k) curSum -= heap.poll()
        ans = Math.max(ans, (curSum * it[0]).toLong())
    }
    return (ans % 1000000007).toInt()
}
