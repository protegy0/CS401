class Item:
    def __init__(self, price):
        self.price = price
    
    def display(self):
        print(f"This item costs {self.price}")
    
    def getPrice(self):
        return self.price