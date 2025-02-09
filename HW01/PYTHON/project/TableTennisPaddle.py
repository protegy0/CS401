from .IndoorItem import IndoorItem

class TableTennisPaddle(IndoorItem):
    def __init__(self, price, style):
        super().__init__(price)
        self.style = style
    
    def display(self):
        print(f"${self.price} - This table tennis paddle is for {self.style}", end="")