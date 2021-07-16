package hashmap


/**
 * https://leetcode.com/problems/4sum/
 * */

fun fourSum(nums: IntArray, target: Int): List<List<Int>> {
    val ans = HashSet<List<Int>>()
    val set = HashSet<Int>()
    for (i in nums.indices) {
        for (j in i + 1 until nums.size)
            for (k in j + 1 until nums.size) {
                val remain = target - (nums[i] + nums[j] + nums[k])
                if (set.contains(remain))
                    ans.add(listOf(nums[i], nums[j], nums[k], remain).sorted())
            }
        set.add(nums[i])
    }
    return ans.toList()
}
