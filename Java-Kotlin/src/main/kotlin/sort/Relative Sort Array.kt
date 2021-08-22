package sort

/**
 * https://leetcode.com/problems/relative-sort-array/
 * */

fun relativeSortArray(arr1: IntArray, arr2: IntArray): IntArray {
    val value = IntArray(1001) { Int.MAX_VALUE }
    for (i in arr2.indices) value[arr2[i]] = i
    return arr1.sortedWith(compareBy<Int> { value[it] }.thenBy { it }).toIntArray()
}