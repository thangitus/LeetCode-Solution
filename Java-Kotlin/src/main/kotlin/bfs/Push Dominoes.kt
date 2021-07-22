package bfs


/**
 * https://leetcode.com/problems/push-dominoes/
 * */

fun pushDominoes(d: String): String {
    val dominoes = StringBuilder('L' + d + 'R')
    val res = StringBuilder()
    var i = 0
    for (j in 1 until dominoes.length) {
        if (dominoes[j] == '.') continue
        val middle = j - i - 1
        if (i > 0) res.append(dominoes[i])
        if (dominoes[i] == dominoes[j])
            for (k in 0 until middle) res.append(dominoes[i])
        else if (dominoes[i] == 'L' && dominoes[j] == 'R')
            for (k in 0 until middle) res.append('.')
        else {
            for (k in 0 until middle / 2)
                res.append('R');
            if (middle % 2 == 1)
                res.append('.');
            for (k in 0 until middle / 2)
                res.append('L');
        }
        i = j
    }
    return res.toString()
}
