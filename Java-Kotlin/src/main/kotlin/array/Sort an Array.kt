package array

/**
 * https://leetcode.com/problems/sort-an-array/
 * */

fun sortArray(nums: IntArray): IntArray {
    mergeSort(nums, 0, nums.size - 1)
    return nums
}

private fun mergeSort(nums: IntArray, l: Int, r: Int) {
    if (l >= r) return
    val m = (r - l) / 2 + l
    mergeSort(nums, l, m)
    mergeSort(nums, m + 1, r)
    merge(nums, l, m, r)
}

private fun merge(nums: IntArray, l: Int, m: Int, r: Int) {
    val tmp = IntArray(r - l + 1)
    var i = l
    var j = m + 1
    var k = 0
    while (i <= m && j <= r)
        if (nums[i] < nums[j]) tmp[k++] = nums[i++]
        else tmp[k++] = nums[j++]
    while (i <= m) tmp[k++] = nums[i++]
    while (j <= r) tmp[k++] = nums[j++]
    for (i in tmp.indices) nums[l + i] = tmp[i]
}
