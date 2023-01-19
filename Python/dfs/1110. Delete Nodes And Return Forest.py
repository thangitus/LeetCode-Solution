from typing import Optional, List

from tree import TreeNode


class Solution:

    def delNodes(self, root: Optional[TreeNode], to_delete: List[int]) -> List[TreeNode]:
        delete_set = set(to_delete)
        res = []

        def dfs(cur, is_root):
            if not cur: return None
            root_deleted = cur.val in delete_set
            if is_root and not root_deleted: res.append(cur)
            cur.left = dfs(cur.left, root_deleted)
            cur.right = dfs(cur.right, root_deleted)
            return None if root_deleted else cur

        dfs(root, True)
        return res
