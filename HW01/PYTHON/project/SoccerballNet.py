from .OutdoorItem import OutdoorItem

class SoccerballNet(OutdoorItem):
    def __init__(self, price, size):
        super().__init__(price)
        self.size = size
             
    def display(self):
        print(f"${self.price} - This soccerball net is {self.size} feet wide", end="")