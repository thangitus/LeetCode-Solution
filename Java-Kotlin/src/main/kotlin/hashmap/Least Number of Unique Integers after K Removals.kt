package hashmap

import java.util.*


/**
 * https://leetcode.com/problems/least-number-of-unique-integers-after-k-removals/
 * */

fun findLeastNumOfUniqueInts(arr: IntArray, k: Int): Int {
    val count: MutableMap<Int, Int> = HashMap()
    arr.forEach { count[it] = count.getOrDefault(it, 0) + 1 }
    val pq = PriorityQueue { o1: Int, o2: Int ->
        count[o1]!! - count[o2]!!
    }
    pq.addAll(count.keys)
    var num = k
    while (num > 0) num -= count[pq.poll()]!!
    return if (num < 0) pq.size + 1 else pq.size
}
