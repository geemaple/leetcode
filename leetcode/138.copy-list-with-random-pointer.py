# Definition for singly-linked list with a random pointer.
# class RandomListNode(object):
#     def __init__(self, x):
#         self.label = x
#         self.next = None
#         self.random = None

class Solution(object):
    def copyRandomList(self, head):
        """
        :type head: RandomListNode
        :rtype: RandomListNode
        """

        if head is None:
            return None

        # append copy node behind its orignal one
        # 1 -> 1' -> 2 -> 2' -> .... -> n -> n' -> None
        current = head
        while (current is not None):
            node = RandomListNode(current.label)
            node.next = current.next
            current.next = node

            current = current.next.next

        # copy random pointers
        current = head
        while(current is not None):
            if current.random is not None:
                current.next.random = current.random.next
            current = current.next.next

        # construct new linked list
        new_head = head.next
        new_cur = new_head
        old_cur = head

        while(new_cur is not None):

            old_cur.next = new_cur.next

            if new_cur.next is not None:
                new_cur.next = new_cur.next.next

            new_cur = new_cur.next
            old_cur = old_cur.next

        return new_head