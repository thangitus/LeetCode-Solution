from typing import Optional

from tree import TreeNode


class Solution:
    def distributeCoins(self, root: Optional[TreeNode]) -> int:
        res = 0

        def dfs(node):
            if not node: return 0
            nonlocal res
            left = dfs(node.left)
            right = dfs(node.right)
            res += abs(left) + abs(right)
            return node.val + left + right - 1

        dfs(root)
        return res
