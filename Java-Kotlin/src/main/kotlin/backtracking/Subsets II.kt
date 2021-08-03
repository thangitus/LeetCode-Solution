package backtracking

import java.util.*

/**
 * https://leetcode.com/problems/subsets-ii/
 * */

lateinit var ans: LinkedList<LinkedList<Int>>
fun subsetsWithDup(nums: IntArray): List<List<Int>> {
    ans = LinkedList()
    nums.sort()
    subsetsWithDup(nums, LinkedList(), 0)
    return ans
}

private fun subsetsWithDup(nums: IntArray, curr: LinkedList<Int>, begin: Int) {
    ans.add(curr.clone() as LinkedList<Int>)
    for (i in begin until nums.size) {
        if (i == begin || nums[i] != nums[i - 1]) {
            curr.add(nums[i])
            subsetsWithDup(nums, curr, i + 1)
            curr.pollLast()
        }
    }
}
