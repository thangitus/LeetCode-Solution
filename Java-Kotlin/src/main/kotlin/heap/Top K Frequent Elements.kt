package heap

import java.util.*
import kotlin.collections.HashMap
import kotlin.collections.HashSet


/**
 * https://leetcode.com/problems/top-k-frequent-elements/
 * */

fun topKFrequent(nums: IntArray, k: Int): IntArray {
    val count = HashMap<Int, Int>()
    nums.forEach {
        count[it] = count.getOrDefault(it, 0) + 1
    }
    val heap = PriorityQueue { a: Int, b: Int ->
        return@PriorityQueue count[a]!! - count[b]!!
    }
    val set = HashSet(nums.toList())
    set.forEach {
        heap.add(it)
    }
    val result = IntArray(k)
    for (i in result.indices)
        result[i] = heap.poll()
    return result
}
