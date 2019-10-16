__author__="bond007"

from node import node

class LinkedListLifo(object):
    def __init__(self):
        self.head = None
        self.length = 0
    def _printList(self):
        node = self.head
        while node:
            print(node.value)
            node = node.pointer
        
