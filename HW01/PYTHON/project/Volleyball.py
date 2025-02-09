from .IndoorItem import IndoorItem

class Volleyball(IndoorItem):
    def __init__(self, price, material, size):
        super().__init__(price)
        self.material = material
        self.size = size
    
    def display(self):
        print(f"${self.price} - This volleyball is made of {self.material} and is {self.size}", end="")