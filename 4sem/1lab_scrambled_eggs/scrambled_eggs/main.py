import os
import pickle
from stove import *
from pan import *
from egg import *
from oil import *
from salt import *
from spices import *
from spatula import *
from dish import *
from states import *

class CookingStateMachine:
    def __init__(self):
        self.stove = Stove()
        self.pan = Pan(self.stove)
        self.egg = None  
        self.dish = Dish()
        self.oil = Oil()
        self.spatula = Spatula()

        self.state_actions = {
            1: self.toggle_stove,
            2: self.heat_pan,
            3: self.add_oil,
            4: self.heat_oil,
            5: self.take_eggs,
            6: self.add_egg,
            7: self.break_egg,
            8: self.add_salt,
            9: self.add_spices,
            10: self.fry,
            11: self.mix,
            12: self.serve,
            13: self.show_status,
            14: self.save_state,
            15: self.load_state,
            16: self.reset_state,
            0: self.exit_program
        }

    def show_menu(self):
        print("\nВыберите действие:")
        print("1: Включить/выключить плиту")
        print("2: Разогреть сковороду")
        print("3: Добавить масло в сковороду")
        print("4: Разогреть масло")
        print("5: Взять яйц(а)")
        print("6: Добавить яйц(а) в сковороду")
        print("7: Разбить яйц(а)")
        print("8: Добавить соль")
        print("9: Добавить специи")
        print("10: Обжарить яйц(а)")
        print("11: Перемешать содержимое сковороды")
        print("12: Подать блюдо")
        print("13: Вывести состояние всех объектов")
        print("14: Сохранить состояние")
        print("15: Загрузить состояние")
        print("16: Сбросить состояние")
        print("0: Выход")
        print(" ")

    def execute_action(self, action):
        if action in self.state_actions:
            self.state_actions[action]()
        else:
            print("Неверный выбор! Попробуйте снова.")

    def take_eggs(self):
        if self.egg is not None:  
            print("Предупреждение: Яйца уже выбраны!")
            return 

        try:
            quantity = int(input("Сколько яиц взять (1-3)? ").strip())
            if 1 <= quantity <= 3:
                self.egg = Egg(quantity)
                print(f"{quantity} яйц(а) выбрано.")
            else:
                print("Неверное количество яиц. Выберите от 1 до 3.")
        except ValueError:
            print("Неверный ввод!")

    def toggle_stove(self):
        choice = input("Выберите (включить(1)/выключить(2) плиту): 1/2: ").strip().lower()
        if choice == "1":
            try:
                self.stove.turn_on()
            except ValueError as e:
                print(e)
        elif choice == "2":
            try:
                self.stove.turn_off(self.pan.get_state())
            except ValueError as e:
                print(e)
        else:
            print("Неверный выбор!")

    def heat_pan(self):
        try:
            self.pan.heat()
        except ValueError as e:
            print(e)

    def add_oil(self):
        try:
            self.pan.add_oil(self.oil)
        except ValueError as e:
            print(e)

    def heat_oil(self):
        try:
            self.pan.heat_oil()
        except ValueError as e:
            print(e)

    def break_egg(self):
        try:
            if self.egg is None:
                raise ValueError("Яйца не выбраны!")
            self.egg.break_egg()
        except ValueError as e:
            print(e)

    def add_egg(self):
        try:
            if self.egg is None:
                raise ValueError("Яйца не выбраны!")
            self.pan.add_ingredient(self.egg)
            print(f"{self.egg.quantity} яйц(а) добавлено в сковороду.")
        except ValueError as e:
            print(e)

    def add_salt(self):
        try:
            self.pan.add_ingredient(Salt())
        except ValueError as e:
            print(e)

    def add_spices(self):
        try:
            self.pan.add_ingredient(Spices())
        except ValueError as e:
            print(e)

    def fry(self):
        try:
            self.pan.fry()
        except ValueError as e:
            print(e)

    def mix(self):
        try:
            self.pan.mix(self.spatula)
        except ValueError as e:
            print(e)

    def serve(self):
        try:
            self.pan.transfer_to_dish(self.dish)
        except ValueError as e:
            print(e)

    def show_status(self):
        print(f"Состояние плиты: {self.stove.state.value}")
        print(f"Состояние сковороды: {self.pan.state.value}")
        print(f"Состояние масла: {self.pan.oil_state.value}")
        print(f"Состояние яиц: {self.egg.state.value if self.egg else 'Нет яиц'}, Количество: {self.egg.quantity if self.egg else 0}")
        print(f"Состояние лопатки: {self.spatula.state.value}")
        print(f"Содержимое блюда: {self.dish.contents}")

    def save_state(self):
        with open("state.pkl", "wb") as f:
            pickle.dump({
                "stove": self.stove,
                "pan": self.pan,
                "egg": self.egg,
                "dish": self.dish,
                "oil": self.oil,
                "spatula": self.spatula
            }, f)
            print("Состояние сохранено!")

    def load_state(self):
        try:
            with open("state.pkl", "rb") as f:
                state = pickle.load(f)
                self.stove = state["stove"]
                self.pan = state["pan"]
                self.egg = state["egg"]
                self.dish = state["dish"]
                self.oil = state["oil"]
                self.spatula = state["spatula"]
                print("Состояние загружено!")
        except FileNotFoundError:
            print("Файл состояния не найден!")

    def reset_state(self):
        if os.path.exists("state.pkl"):
            os.remove("state.pkl")
            print("Сохраненное состояние удалено.")

        self.stove = Stove()
        self.pan = Pan(self.stove)
        self.egg = None
        self.dish = Dish()
        self.oil = Oil()
        self.spatula = Spatula()

        print("Текущее состояние объектов сброшено!")

    def exit_program(self):
        print("Выход из программы.")
        exit()

def main():
    cooking_machine = CookingStateMachine()
    print(" ")
    print("🥚🥚🥚СИМУЛЯТОР ПРИГОТОВЛЕНИЯ ЯИЧНИЦЫ🥚🥚🥚")
    print(" ")
    while True:
        action = input("Введите номер действия или любую клавишу для меню: ")
        print(" ")
        if action.isdigit():
            action = int(action)
            cooking_machine.execute_action(action)
        else:
            cooking_machine.show_menu()

if __name__ == "__main__":
    main()
