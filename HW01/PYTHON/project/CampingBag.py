from .OutdoorItem import OutdoorItem

class CampingBag(OutdoorItem):
    def __init__(self, price, size, thickness):
        super().__init__(price)
        self.size = size
        self.thickness = thickness
        
    def display(self):
        print(f"${self.price} - This camping bag is size {self.size} and has a thickness of {self.thickness} inches", end="")