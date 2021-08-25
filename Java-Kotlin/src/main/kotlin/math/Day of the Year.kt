package math

import java.time.LocalDate

/**
 * https://leetcode.com/problems/day-of-the-week/
 * */

fun dayOfYear(date: String): Int {
    val tokens = date.split('-').map { it.toInt() }
    return LocalDate.of(tokens[0], tokens[1], tokens[2]).dayOfYear
}