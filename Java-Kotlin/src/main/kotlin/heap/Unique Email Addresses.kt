package heap

import java.util.*


/**
 * https://leetcode.com/problems/unique-email-addresses/
 * */

fun numUniqueEmails(emails: Array<String>): Int {
    val hashSet = HashSet<String>()
    emails.forEach { email ->
        val tokens = email.split('@')
        val local = tokens[0].split('+')[0].replace(".", "")
        val domain = tokens[1]
        hashSet.add("$local@$domain")
    }
    return hashSet.size
}
