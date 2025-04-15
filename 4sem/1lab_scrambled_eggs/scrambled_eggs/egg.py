from states import *

class Egg:
    def __init__(self, quantity: int = 1) -> None:
        if quantity < 1 or quantity > 3:
            raise ValueError("Можно добавить только от 1 до 3 яиц.")
        self.quantity = quantity  
        self.state = EggState.UNBROKEN

    def break_egg(self) -> None:
        if self.state != EggState.UNBROKEN:
            raise ValueError(f"Яйца уже {self.state.value.lower()}!")  
        self.state = EggState.BROKEN
        print(f"{self.quantity} яйц(а) разбито.")