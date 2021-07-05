package matrix


/**
 * https://leetcode.com/problems/reshape-the-matrix/
 * */

fun matrixReshape(mat: Array<IntArray>, r: Int, c: Int): Array<IntArray> {
    val n = mat.size
    val m = mat[0].size
    if (n * m != r * c) return mat
    val ans = Array(r) { IntArray(c) }
    for (i in mat.indices)
        for (j in mat[0].indices) {
            val index = i * m + j
            ans[index / c][index % c] = mat[i][j]
        }
    return ans
}
