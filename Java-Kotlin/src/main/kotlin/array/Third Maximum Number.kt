package array

import java.util.*

/**
 * https://leetcode.com/problems/third-maximum-number/
 * */

fun thirdMax(nums: IntArray): Int {
    val heap = PriorityQueue<Int>()
    nums.forEach {
        if (it in heap) return@forEach
        if (heap.size < 3) heap.add(it)
        else if (it > heap.peek()) {
            heap.poll()
            heap.add(it)
        }
    }
    if (heap.size < 3)
        while (heap.size > 1) heap.poll()
    return heap.poll()
}
