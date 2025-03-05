from states import *
from egg import *
from salt import *
from spices import *
from spatula import *
from stove import *
from oil import *

class Pan:
    def __init__(self, stove) -> None:
        self.state = PanState.COLD 
        self.stove = stove
        self.ingredients = []
        self.oil_state = OilState.NOT_HEATED
        self.fry_count = 0
        self.mixed = False

    def heat(self) -> None:
        if self.stove.state != StoveState.ON:
            raise ValueError("Плита выключена! Нельзя нагреть сковороду.")
        if self.state == PanState.HOT:
            raise ValueError("Сковорода уже разогрета!")
        if self.state == PanState.COLD:
            self.state = PanState.HEATING
            print("Сковорода разогревается...")
        elif self.state == PanState.HEATING:
            self.state = PanState.HOT
            print("Сковорода разогрета!")

    def add_oil(self, oil) -> None:
        self.ingredients.append(oil)
        print("Масло добавлено в сковороду.")

    def heat_oil(self) -> None:
        if self.state != PanState.HOT:
            raise ValueError("Сковорода недостаточно горячая для разогрева масла!")

        for ing in self.ingredients:
            if isinstance(ing, Oil):
                ing.state = OilState.HEATED
                self.oil_state = OilState.HEATED
                print("Масло разогрето.")
                return

        raise ValueError("В сковороде нет масла для разогрева!")
    
    def add_ingredient(self, ingredient) -> None:

        if isinstance(ingredient, Egg):
            if any(isinstance(i, Egg) for i in self.ingredients):
                raise ValueError("Яйцо уже добавлено в сковороду!")            
            if ingredient.state != EggState.BROKEN:
                raise ValueError("Яйцо должно быть разбито!")
            if self.oil_state != OilState.HEATED:
                raise ValueError("Нельзя добавить яйцо без разогретого масла!")
            
        if isinstance(ingredient, (Salt, Spices)) and not any(isinstance(i, Egg) for i in self.ingredients):
            raise ValueError("Нельзя добавлять соль или специи без яйца в сковороде!")    

        self.ingredients.append(ingredient)

        if isinstance(ingredient, Egg):
            print("Яйцо добавлено в сковороду.")
        if isinstance(ingredient, Salt):
            print("Яичница посолена.")
        if isinstance(ingredient, Spices):
            print("Яичница усыпана специями.")
    
    def fry(self) -> None:
        egg = next((i for i in self.ingredients if isinstance(i, Egg)), None)
        if egg is None:
            raise ValueError("В сковороде нет яйца для жарки!")

        if self.state != PanState.HOT:
            raise ValueError("Сковорода должна быть горячей для обжарки!")
        
        if self.oil_state != OilState.HEATED:
            raise ValueError("Нельзя жарить без разогретого масла!")
        
        self.fry_count += 1

        if self.fry_count > 3:
            egg.state = EggState.BURNT
            print("Яичница сгорела!")
            return
    
        egg.state = EggState.FRYING
        print(f"Яйцо обжаривается... ({self.fry_count}/3)")

        if self.fry_count == 3:
            egg.state = EggState.COOKED
            print("Яичница готова!")
    
    def mix(self, spatula) -> None:
        if self.fry_count == 0:
            raise ValueError("Сначала нужно обжарить яйцо!")

        self.mixed = True
        spatula.state = SpatulaState.USED 
        print("Содержимое перемешано лопаткой. Будет болтунья!")

    def transfer_to_dish(self, dish) -> None:
        egg = next((i for i in self.ingredients if isinstance(i, Egg)), None)
 
        if egg is None:
            raise ValueError("Нечего подавать!")

        if egg.state == EggState.BURNT:
            dish.contents = "Сгоревшая яичница"
            print(f"Блюдо {dish.contents} подано! ПРИЯТНОГО АППЕТИТА")
        elif egg.state != EggState.COOKED:
            raise ValueError("Блюдо ещё не готово!")  
        else:
            dish.contents = "Болтунья" if self.mixed else "Глазунья"

            seasonings = [i for i in self.ingredients if isinstance(i, (Salt, Spices))]

            if seasonings:
                seasoning_names = " и ".join(i.name for i in seasonings)
                dish.contents += f" с {seasoning_names}"

            print(f"Блюдо {dish.contents} подано! ПРИЯТНОГО АППЕТИТА")

        self.ingredients.clear()
        self.fry_count = 0
        self.mixed = False

