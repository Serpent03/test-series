class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def mergeKLists(self, lists):
        # stack based approach, it seems like
        nodes = []
        for l in lists:
            while l:
                nodes.append(l.val)
                l = l.next

        nodes.sort()
        head = ListNode()
        ptr = head
        for val in nodes:
            ptr.next = ListNode(val)
            ptr = ptr.next

        return head.next
