package heap

import java.util.*


/**
 * https://leetcode.com/problems/maximum-product-of-two-elements-in-an-array/
 * */

fun maxProduct(nums: IntArray): Int {
    val minHeap = PriorityQueue<Int>()
    val maxHeap = PriorityQueue<Int>(Collections.reverseOrder())
    nums.forEach {
        minHeap.add(it - 1)
        maxHeap.add(it - 1)
    }
    return Math.max(minHeap.poll() * minHeap.poll(), maxHeap.poll() * maxHeap.poll())
}
