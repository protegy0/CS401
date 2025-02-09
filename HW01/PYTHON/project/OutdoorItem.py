from .Item import Item

class OutdoorItem(Item):
    def __init__(self, price):
        super().__init__(price)
    
    def display(self):
        print(f"This outdoor item costs {self.price}")