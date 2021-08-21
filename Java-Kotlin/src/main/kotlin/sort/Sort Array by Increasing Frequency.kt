package sort


/**
 * https://leetcode.com/problems/sort-array-by-increasing-frequency/
 * */

fun frequencySort(nums: IntArray): IntArray {
    val map = HashMap<Int, Int>()
    nums.forEach {
        val frequency = map.getOrDefault(it, 0)
        map[it] = frequency + 1
    }
    return nums.sortedWith(compareBy<Int> { map[it] }.thenByDescending { it }).toIntArray()
}