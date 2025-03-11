from states import *

class Stove:
    def __init__(self) -> None:
        self.state = StoveState.OFF  

    def turn_on(self) -> None:
        if self.state == StoveState.ON:
            raise ValueError("Ошибка: Плита уже включена.")  
        
        self.state = StoveState.ON
      
        print("Плита включена.")

    def turn_off(self) -> None:
        if self.state == StoveState.OFF:
            raise ValueError("Ошибка: Плита уже выключена.")  
        
        self.state = StoveState.OFF
      
        print("Плита выключена.")

    def turn_off(self, pan_state: str) -> None:
        if self.state == StoveState.OFF:
            raise ValueError("Ошибка: Плита уже выключена.")
        
        if pan_state == PanState.HOT:
            raise ValueError("Нельзя прервать священный процесс готовки!")

        self.state = StoveState.OFF
        print("Плита выключена.")