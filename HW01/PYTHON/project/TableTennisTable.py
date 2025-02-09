from .IndoorItem import IndoorItem

class TableTennisTable(IndoorItem):
    def __init__(self, price, material):
        super().__init__(price)
        self.material = material
    
    def display(self):
        print(f"${self.price} - This table tennis paddle is made of {self.material}", end="")