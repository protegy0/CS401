from .Item import Item

class IndoorItem(Item):
    def __init__(self, price):
        super().__init__(price)
    
    def display(self):
        print(f"This indoor item costs {self.price}", end="")