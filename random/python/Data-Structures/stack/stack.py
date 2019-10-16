__author__ = "switchkiller"
class Stack:
    def __init__(self):
        self.content = []
    def push(self, item):
        self.content.append(item)
    def push(self):
        return self.content.pop()
    def isEmpty(self):
        return (self.items == [])
    def peek(self):
        return self.content
    def __str__(self):
        return str(self.content)
