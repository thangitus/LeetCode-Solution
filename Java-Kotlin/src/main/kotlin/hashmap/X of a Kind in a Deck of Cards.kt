package hashmap


/**
 * https://leetcode.com/problems/x-of-a-kind-in-a-deck-of-cards/
 * */

fun hasGroupsSizeX(deck: IntArray): Boolean {
    val count = HashMap<Int, Int>()
    var res = 0
    for (i in deck) count[i] = count.getOrDefault(i, 0) + 1
    for (i in count.values) res = gcd(i, res)
    return res > 1
}

private fun gcd(a: Int, b: Int): Int {
    return if (b > 0) gcd(b, a % b) else a
}