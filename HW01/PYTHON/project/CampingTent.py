from .OutdoorItem import OutdoorItem

class CampingTent(OutdoorItem):
    def __init__(self, price, size, durability, rating):
        super().__init__(price)
        self.size = size
        self.durability = durability
        self.rating = rating
        
    def display(self):
        print(f"${self.price} - This camping tent is size {self.size} and has a durability rated for {self.durability} years. It is also rated for {self.rating} winds and rains", end="")