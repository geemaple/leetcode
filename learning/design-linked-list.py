class Node(object):
    def __init__(self, val):
        self.val = val
        self.next = None

class MyLinkedList(object):

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.head = Node(None)

    def get(self, index):
        """
        Get the value of the index-th node in the linked list. If the index is invalid, return -1.
        :type index: int
        :rtype: int
        """
        current = self.head
        for _ in range(index):
            if current.next is not None:
                current = current.next
            else:
                return -1
        
        result = current.next
        return result.val if result is not None else -1
        

    def addAtHead(self, val):
        """
        Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list.
        :type val: int
        :rtype: void
        """
        node = Node(val)
        node.next = self.head.next
        self.head.next = node


    def addAtTail(self, val):
        """
        Append a node of value val to the last element of the linked list.
        :type val: int
        :rtype: void
        """
        
        current = self.head
        node = Node(val)
        while(current.next is not None):
            current = current.next

        current.next = node

    def addAtIndex(self, index, val):
        """
        Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted.
        :type index: int
        :type val: int
        :rtype: void
        """
        
        count = 0
        current = self.head        
        while(current.next is not None):
            if count == index:
                break
            count += 1
            current = current.next
        
        if index > count:
            return
        
        node = Node(val)
        node.next = current.next
        current.next = node
        

    def deleteAtIndex(self, index):
        """
        Delete the index-th node in the linked list, if the index is valid.
        :type index: int
        :rtype: void
        """
        count = 0
        current = self.head
        while(current.next is not None):
            if count == index:
                break
            count += 1
            current = current.next
        
        if index > count:
            return
        
        node = current.next
        current.next = node.next
        node.next = None