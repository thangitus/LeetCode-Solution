# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeInBetween(self, list1: ListNode, a: int, b: int, list2: ListNode) -> ListNode:
        dummy = ListNode(0, list1)
        prev_a, next_b, cur = None, None, dummy
        for i in range(b + 1):
            if i == a:
                prev_a = cur
            cur = cur.next
        next_b = cur.next
        prev_a.next = list2
        while list2.next:
            list2 = list2.next
        list2.next = next_b
        return dummy.next
