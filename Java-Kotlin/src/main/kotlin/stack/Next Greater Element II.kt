package stack

import java.util.*

/**
 * https://leetcode.com/problems/next-greater-element-ii/
 * */

fun nextGreaterElements(nums: IntArray): IntArray {
    val n = nums.size
    val stack = Stack<Int>()
    val ans = IntArray(n) { -1 }
    for (i in 0 until n * 2) {
        while (!stack.empty() && nums[stack.peek()] < nums[i % n])
            ans[stack.pop()] = nums[i % n]
        stack.push(i % n)
    }
    return ans
}