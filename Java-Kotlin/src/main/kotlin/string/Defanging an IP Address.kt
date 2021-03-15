package string

import java.lang.StringBuilder

// https://leetcode.com/problems/defanging-an-ip-address/

fun defangIPaddr(address: String): String {
    val builder = StringBuilder()
    for (c in address)
        if (c == '.') builder.append("[.]")
        else builder.append(c)
    return builder.toString()
}
