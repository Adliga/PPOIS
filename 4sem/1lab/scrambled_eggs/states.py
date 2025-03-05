from enum import Enum

class StoveState(Enum):
    OFF = "Выключена"
    ON = "Включена"
    
class PanState(Enum):
    COLD = "Холодная"
    HEATING = "Разогревается"
    HOT = "Горячая"

class OilState(Enum):
    NOT_HEATED = "Не разогрето"
    HEATED = "Разогрето"

class EggState(Enum):
    UNBROKEN = "Неразбито"
    BROKEN = "Разбито"
    FRYING = "Жарится"
    COOKED = "Готово"
    BURNT = "Сгорело"

class SpatulaState(Enum):
    NOT_USED = "Не используется"
    USED = "Используется"
