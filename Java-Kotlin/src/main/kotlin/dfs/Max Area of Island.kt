package dfs

/**
 * https://leetcode.com/problems/max-area-of-island/
 * */

fun maxAreaOfIsland(grid: Array<IntArray>): Int {
    var ans = 0
    for (i in grid.indices)
        for (j in grid[0].indices)
            if (grid[i][j] == 1)
                ans = Math.max(dfs(grid, i, j), ans)
    return ans
}

private fun dfs(grid: Array<IntArray>, x: Int, y: Int): Int {
    if (x < 0 || y < 0 || x == grid.size || y == grid[0].size || grid[x][y] == 0)
        return 0
    grid[x][y] = 0
    val left = dfs(grid, x, y - 1)
    val right = dfs(grid, x, y + 1)
    val top = dfs(grid, x - 1, y)
    val bottom = dfs(grid, x + 1, y)
    return left + right + top + bottom + 1
}
