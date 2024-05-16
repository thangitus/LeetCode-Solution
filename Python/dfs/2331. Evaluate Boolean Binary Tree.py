from typing import Optional

from tree import TreeNode


class Solution:
    def evaluateTree(self, root: Optional[TreeNode]) -> bool:
        if root.val == 1 or root.val == 0:
            return bool(root.val)
        left = self.evaluateTree(root.left)
        right = self.evaluateTree(root.right)
        if root.val == 2:
            return left or right
        return left and right
