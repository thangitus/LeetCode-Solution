package hashmap


/**
 * https://leetcode.com/problems/word-pattern/
 * */

fun wordPattern(pattern: String, s: String): Boolean {
    val words = s.split(' ')
    if (pattern.length != words.size) return false
    val flags = BooleanArray(127) { false }
    val map = HashMap<String, Char>()
    for (i in pattern.indices)
        if (map.containsKey(words[i])) {
            if (map[words[i]] != pattern[i])
                return false
        } else if (flags[pattern[i].toInt()])
            return false
        else {
            map[words[i]] = pattern[i]
            flags[pattern[i].toInt()] = true
        }
    return true
}