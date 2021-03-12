package string

//https://leetcode.com/problems/roman-to-integer/

fun romanToInt(s: String): Int {
    var ans = 0
    for (i in s.indices) {
        ans += when (s[i]) {
            'I' -> {
                if (i < s.length - 1 && (s[i + 1] == 'V' || s[i + 1] == 'X'))
                    -1
                else 1
            }
            'V' -> 5
            'X' -> {
                if (i < s.length - 1 && (s[i + 1] == 'L' || s[i + 1] == 'C'))
                    -10
                else 10
            }
            'L' -> 50
            'C' -> {
                if (i < s.length - 1 && (s[i + 1] == 'D' || s[i + 1] == 'M'))
                    -100
                else 100
            }
            'D' -> 500
            'M' -> 1000
            else -> 0
        }
    }
    return ans
}
