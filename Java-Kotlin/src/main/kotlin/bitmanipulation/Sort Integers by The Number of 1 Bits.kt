package bitmanipulation

/**
 * https://leetcode.com/problems/sort-integers-by-the-number-of-1-bits/
 * */

fun sortByBits(arr: IntArray) =
    arr.sortedWith(compareBy<Int> { Integer.bitCount(it) }.thenBy { it }).toIntArray()
