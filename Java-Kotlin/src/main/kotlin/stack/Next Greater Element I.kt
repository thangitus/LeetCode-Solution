package stack

import java.util.*
import kotlin.collections.HashMap

/**
 * https://leetcode.com/problems/next-greater-element-i/
 * */

fun nextGreaterElement(nums1: IntArray, nums2: IntArray): IntArray {
    val map = HashMap<Int, Int>()
    val stack = Stack<Int>()
    nums2.forEach {
        while (!stack.empty() && stack.peek() < it)
            map[stack.pop()] = it
        stack.add(it)
    }
    val ans = IntArray(nums1.size)
    for (i in nums1.indices)
        ans[i] = map.getOrDefault(nums1[i], -1)
    return ans
}