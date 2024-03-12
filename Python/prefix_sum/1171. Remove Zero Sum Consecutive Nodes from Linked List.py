from typing import Optional


class Solution:
    def removeZeroSumSublists(self, head: Optional[ListNode]) -> Optional[ListNode]:
        front = ListNode(0, head)
        prefix_sum = {0: front}
        cur, prefix = front, 0
        while cur:
            prefix += cur.val
            prefix_sum[prefix] = cur
            cur = cur.next

        cur, prefix = front, 0
        while cur:
            prefix += cur.val
            cur.next = prefix_sum[prefix].next
            cur = cur.next

        return front.next
