from .OutdoorItem import OutdoorItem

class Soccerball(OutdoorItem):
    def __init__(self, price, material):
        super().__init__(price)
        self.material = material
             
    def display(self):
        print(f"${self.price} - This soccerball is made of {self.material}", end="")