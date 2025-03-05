from states import *

class Egg:
    def __init__(self) -> None:
        self.state = EggState.UNBROKEN

    def break_egg(self) -> None:
        if self.state == EggState.BROKEN:
            raise ValueError("Яйцо уже разбито!")
        self.state = EggState.BROKEN
        print("Яйцо разбито.")
