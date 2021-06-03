package array

/**
 * https://leetcode.com/problems/average-salary-excluding-the-minimum-and-maximum-salary/
 * */

fun average(salary: IntArray): Double {
    var sum = 0
    var min = salary[0]
    var max = salary[0]
    salary.forEach {
        sum += it
        min = Math.min(it, min)
        max = Math.max(it, max)
    }
    return ((sum - min - max) / (salary.size - 2.0))
}
