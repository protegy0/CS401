from .IndoorItem import IndoorItem

class TableTennisBall(IndoorItem):
    def __init__(self, price):
        super().__init__(price)
    
    def display(self):
        print(f"${self.price} - A standard table tennis ball", end="")