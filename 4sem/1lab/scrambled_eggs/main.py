import argparse
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
import sys

sys.stdout.reconfigure(encoding='utf-8')

def save_state(stove, pan, egg, dish, oil, spatula, filename="state.pkl") -> None:
    with open(filename, 'wb') as f:
        pickle.dump({
            "stove": stove,
            "pan": pan,
            "egg": egg,
            "dish": dish,
            "oil": oil,
            "spatula": spatula
        }, f)

def load_state(filename = "state.pkl") -> None:
    try:
        with open(filename, 'rb') as f:
            state = pickle.load(f)
        return state
    except FileNotFoundError:
        return None

def print_status(stove, pan, egg, spatula, dish) -> None:
    print(f"Состояние плиты: {stove.state.value}")
    print(f"Состояние сковороды: {pan.state.value}")
    print(f"Состояние масла: {pan.oil_state.value}")
    print(f"Состояние яйца: {egg.state.value}")
    print(f"Состояние лопатки: {spatula.state.value}")
    print(f"Содержимое блюда: {dish.contents}")

def reset_state(filename="state.pkl") -> None:
    if os.path.exists(filename):
        os.remove(filename)
        print("Состояние сброшено!")
    else:
        print("Файл состояния отсутствует, сбрасывать нечего.")

def main() -> None:
    parser = argparse.ArgumentParser(description="Управление процессом готовки.")

    parser.add_argument("--stove", choices=["on", "off"], help="Включить или выключить плиту.")
    parser.add_argument("--heat-pan", action="store_true", help="Разогреть сковороду.")
    parser.add_argument("--add-oil", action="store_true", help="Добавить масло в сковороду.")
    parser.add_argument("--heat-oil", action="store_true", help="Разогреть масло.")
    parser.add_argument("--add-egg", action="store_true", help="Добавить яйцо в сковороду.")
    parser.add_argument("--break-egg", action="store_true", help="Разбить яйцо.")
    parser.add_argument("--add-salt", action="store_true", help="Добавить соль.")
    parser.add_argument("--add-spices", action="store_true", help="Добавить специи.")
    parser.add_argument("--fry", action="store_true", help="Обжарить яйцо.")
    parser.add_argument("--mix", action="store_true", help="Перемешать содержимое сковороды.")
    parser.add_argument("--serve", action="store_true", help="Подать блюдо.")
    parser.add_argument("--status", action="store_true", help="Вывести список состояний всех объектов.")
    parser.add_argument("--reset", action="store_true", help="Сбросить все состояния объектов.")

    args = parser.parse_args()
    state = load_state()

    if state is None:
        stove = Stove()
        pan = Pan(stove)
        egg = Egg()
        dish = Dish()
        oil = Oil()
        spatula = Spatula()
    else:
        stove = state["stove"]
        pan = state["pan"]
        egg = state["egg"]
        dish = state["dish"]
        oil = state["oil"]
        spatula = state["spatula"]

    if args.stove == "on":
        try:
            stove.turn_on()
        except ValueError as e:
            print(e)
    elif args.stove == "off":
        try:
            stove.turn_off()
        except ValueError as e:
            print(e)

    if args.heat_pan:
        try:
            pan.heat()
        except ValueError as e:
            print(e)

    if args.add_oil:
        try:
            pan.add_oil(oil)
        except ValueError as e:
            print(e)
    
    if args.heat_oil:
        try:
            pan.heat_oil()
        except ValueError as e:
            print(e)

    if args.add_egg:
        try:
            pan.add_ingredient(egg)
        except ValueError as e:
            print(e)

    if args.break_egg:
        try:
            egg.break_egg()
        except ValueError as e:
            print(e)        

    if args.add_salt:
        try:
            pan.add_ingredient(Salt())
        except ValueError as e:
            print(e)           

    if args.add_spices:
        try:
            pan.add_ingredient(Spices())
        except ValueError as e:
            print(e)           

    if args.fry:
        try:
            pan.fry()
        except ValueError as e:
            print(e)

    if args.mix:
        try:
            pan.mix(spatula)
        except ValueError as e:
            print(e)

    if args.serve:
        try:
            pan.transfer_to_dish(dish)
        except ValueError as e:
            print(e)
    
    if args.status:
        print_status(stove, pan, egg, spatula, dish)

    save_state(stove, pan, egg, dish, oil, spatula)

    if args.reset:
        reset_state()
        return


if __name__ == "__main__":
    main()
