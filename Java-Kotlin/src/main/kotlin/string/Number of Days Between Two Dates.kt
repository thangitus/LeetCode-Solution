package string

import java.text.SimpleDateFormat
import java.util.concurrent.TimeUnit


/**
 * https://leetcode.com/problems/number-of-days-between-two-dates/
 * */

fun daysBetweenDates(date1: String, date2: String): Int {
    val simpleDateFormat = SimpleDateFormat("yyyy-MM-dd")
    val d1 = simpleDateFormat.parse(date1)
    val d2 = simpleDateFormat.parse(date2)
    return TimeUnit.DAYS.convert(Math.abs(d1.time - d2.time), TimeUnit.MILLISECONDS).toInt()
}

