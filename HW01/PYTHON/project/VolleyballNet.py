from .IndoorItem import IndoorItem

class VolleyballNet(IndoorItem):
    def __init__(self, price, type, size):
        super().__init__(price)
        self.type = type
        self.size = size
    
    def display(self):
        print(f"${self.price} - This volleyball net is made for {self.type}s and is {self.size}", end="")