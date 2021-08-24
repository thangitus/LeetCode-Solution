package math

import java.time.LocalDate

/**
 * https://leetcode.com/problems/day-of-the-week/
 * */

fun dayOfTheWeek(day: Int, month: Int, year: Int): String {
    val stringBuilder = StringBuilder(LocalDate.of(year, month, day).dayOfWeek.name.toLowerCase())
    stringBuilder[0] = stringBuilder[0].toUpperCase()
    return stringBuilder.toString()
}