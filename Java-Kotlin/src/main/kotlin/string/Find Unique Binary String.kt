package string

import java.lang.StringBuilder


/**
 * https://leetcode.com/problems/find-unique-binary-string/
 * */

fun findDifferentBinaryString(nums: Array<String>): String {
    val set = HashSet<Int>()
    nums.forEach {
        set.add(Integer.parseInt(it, 2))
    }
    val max = 1.shl(nums.size)
    val num = StringBuilder()
    for (i in 0..max)
        if (!set.contains(i)) {
            num.append(Integer.toBinaryString(i))
            break
        }
    val res = StringBuilder()
    while (res.length < nums.size - num.length)
        res.append('0')
    res.append(num)
    return res.toString()
}