package dp

import java.util.*
import kotlin.collections.HashMap

/**
 * https://leetcode.com/problems/jump-game-vi/
 * */

fun maxResult(nums: IntArray, k: Int): Int {
    val dp = IntArray(nums.size)
    val maxHeap = PriorityQueue<Int>(Collections.reverseOrder())
    val deleted = HashMap<Int, Int>()
    dp[0] = nums[0]
    maxHeap.add(dp[0])
    for (i in 1 until nums.size) {
        while (i - k >= 0 && deleted.containsKey(maxHeap.peek()) && deleted[maxHeap.peek()] != 0) {
            val value: Int = deleted[maxHeap.peek()]!!
            deleted[maxHeap.poll()] = value - 1
        }
        dp[i] = nums[i] + maxHeap.peek()
        maxHeap.add(dp[i])
        if (i - k >= 0) {
            if (deleted.containsKey(dp[i - k])) {
                val value = deleted[dp[i - k]]!!
                deleted[dp[i - k]] = value + 1
            } else deleted[dp[i - k]] = 1
        }
    }
    return dp[dp.size - 1]
}
