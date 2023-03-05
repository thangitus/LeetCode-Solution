from queue import Queue
from typing import Optional

from tree.TreeNode import TreeNode


class Solution:
    def kthLargestLevelSum(self, root: Optional[TreeNode], k: int) -> int:
        queue = Queue()
        queue.put(root)
        sums = []
        while not queue.empty():
            sum = 0
            for i in range(queue.qsize()):
                cur = queue.get()
                sum += cur.val
                if cur.left is not None: queue.put(cur.left)
                if cur.right is not None: queue.put(cur.right)
            sums += [sum]
        sums.sort(reverse=True)
        return sums[k - 1] if k <= len(sums) else -1
