from .OutdoorItem import OutdoorItem

class CampingStove(OutdoorItem):
    def __init__(self, price, wattage, size):
        super().__init__(price)
        self.wattage = wattage
        self.size = size
        
    def display(self):
        print(f"${self.price} - This camping stove is size {self.size} and has a wattage of {self.wattage}", end="")