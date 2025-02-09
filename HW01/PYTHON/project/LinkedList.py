class Node:
    def __init__(self, item, type, stock):
        self.item = item
        self.type = type
        self.stock = stock
        self.next = None
        self.ID = None
        
    def setID(self, ID):
        self.ID = ID
        
    def setNext(self, next):
        self.next = next

class LinkedList:
    def __init__(self):
        self.head = None
        self.count = 0
        
    def getHead(self):
        return self.head
    
    
    def insertAtBeginning(self, item, type, stock):
        newNode = Node(item, type, stock)
        self.count += 1
        newNode.setID(self.count)
        newNode.setNext(self.head)
        self.head = newNode