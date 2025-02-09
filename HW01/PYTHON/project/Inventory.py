from .LinkedList import LinkedList

class Inventory:
    def __init__(self):
        self.IndoorInventory = LinkedList()
        self.OutdoorInventory = LinkedList()
        
    def addIndoorItem(self, item, category, stock):
        self.IndoorInventory.insertAtBeginning(item, category, stock)
        
    def addOutdoorItem(self, item, category, stock):
        self.OutdoorInventory.insertAtBeginning(item, category, stock)
    
    def displayIndoorItems(self):
        node = self.IndoorInventory.getHead()
        
        while (node is not None):
            print(f"ID: {node.ID} - ", end="")
            node.item.display()
            print(f" - Current stock: {node.stock}")
            node = node.next
            
    def displayOutdoorItems(self):
        node = self.OutdoorInventory.getHead()
        
        while (node is not None):
            print(f"ID: {node.ID} - ", end="")
            node.item.display()
            print(f" - Current stock: {node.stock}")
            node = node.next
    
    def displayVolleyballItems(self):
        node = self.IndoorInventory.getHead()
        while (node is not None):
            if (node.type == "vb"):
                print(f"ID: {node.ID} - ", end="")
                node.item.display()
                print(f" - Current stock: {node.stock}")
            node = node.next
            
    def displayTabletennisItems(self):
        node = self.IndoorInventory.getHead()
        while (node is not None):
            if (node.type == "tt"):
                print(f"ID: {node.ID} - ", end="")
                node.item.display()
                print(f" - Current stock: {node.stock}")
            node = node.next
            
    def displayCampingItems(self):
        node = self.OutdoorInventory.getHead()
        while (node is not None):
            if (node.type == "c"):
                print(f"ID: {node.ID} - ", end="")
                node.item.display()
                print(f" - Current stock: {node.stock}")
            node = node.next

    def displaySoccerItems(self):
        node = self.OutdoorInventory.getHead()
        while (node is not None):
            if (node.type == "s"):
                print(f"ID: {node.ID} - ", end="")
                node.item.display()
                print(f" - Current stock: {node.stock}")
            node = node.next
                
    def buyItem(self, ID, page):
        node = None
        if (page == "i"):
            node = self.IndoorInventory.getHead()
        else:
            node = self.OutdoorInventory.getHead()
        item = None
        
        while (node is not None):
            if (node.ID == ID):
                item = node.item
                break
            node = node.next
        
        if (node is None):
            print("That item ID does not exist")
            return
        
        amount = int(input("Please enter the amount you would like to purchase: "))
        
        while (amount <= 0):
            amount = int(input("Please enter a number above zero: "))
            
        if (node.stock < amount):
            print(f"There is not enough of that item to purchase {amount}!")
            return
        
        price = round((item.getPrice() * amount), 2)
        
        choice = input(f"It will cost ${price} to purchase. Are you sure? (Y/N): ")
        
        if (choice.lower() == "y" or choice.lower() == "yes"):
            node.stock -= amount
            print("Successfully purchased!")
        
        
        
        
        
    
    
        