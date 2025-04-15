import unittest
from pan import *
from egg import *
from spatula import *
from stove import *
from oil import *
from dish import *
from salt import *
from spices import *
from states import *
import sys

sys.stdout.reconfigure(encoding='utf-8')

class TestPanHeat(unittest.TestCase):
    def test_heat_success(self):
        stove = Stove()
        stove.turn_on()
        pan = Pan(stove)
        pan.heat()
        self.assertEqual(pan.state, PanState.HEATING)

    def test_heat_stove_off(self):
        stove = Stove()
        pan = Pan(stove)
        with self.assertRaises(ValueError):
            pan.heat()

    def test_heat_already_hot(self):
        stove = Stove()
        stove.turn_on()
        pan = Pan(stove)
        pan.heat()  
        pan.heat() 
        with self.assertRaises(ValueError):
            pan.heat() 

class TestPanAddOil(unittest.TestCase):
    def test_add_oil_success(self):
        stove = Stove()
        pan = Pan(stove)
        oil = Oil()
        pan.add_oil(oil)
        self.assertIn(oil, pan.ingredients)

class TestPanHeatOil(unittest.TestCase):
    def test_heat_oil_success(self):
        stove = Stove()
        stove.turn_on()
        pan = Pan(stove)
        pan.heat() 
        pan.heat()  
        oil = Oil()
        pan.add_oil(oil)
        pan.heat_oil()
        self.assertEqual(pan.oil_state, OilState.HEATED)

    def test_heat_oil_pan_not_hot(self):
        stove = Stove()
        pan = Pan(stove)
        oil = Oil()
        pan.add_oil(oil)
        with self.assertRaises(ValueError):
            pan.heat_oil()

    def test_heat_oil_no_oil(self):
        stove = Stove()
        stove.turn_on()
        pan = Pan(stove)
        pan.heat()  
        pan.heat()  
        with self.assertRaises(ValueError):
            pan.heat_oil()

class TestPanAddIngredient(unittest.TestCase):
    def test_add_egg_success(self):
        stove = Stove()
        stove.turn_on()
        pan = Pan(stove)
        pan.heat() 
        pan.heat() 
        oil = Oil()
        pan.add_oil(oil)
        pan.heat_oil()
        egg = Egg()
        egg.break_egg()
        pan.add_ingredient(egg)
        self.assertIn(egg, pan.ingredients)

    def test_add_egg_not_broken(self):
        stove = Stove()
        stove.turn_on()
        pan = Pan(stove)
        pan.heat()  
        pan.heat()  
        oil = Oil()
        pan.add_oil(oil)
        pan.heat_oil()
        egg = Egg()
        with self.assertRaises(ValueError):
            pan.add_ingredient(egg)

    def test_add_salt_without_egg(self):
        stove = Stove()
        pan = Pan(stove)
        salt = Salt()
        with self.assertRaises(ValueError):
            pan.add_ingredient(salt)

class TestPanFry(unittest.TestCase):
    def test_fry_success(self):
        stove = Stove()
        stove.turn_on()
        pan = Pan(stove)
        pan.heat()  
        pan.heat() 
        oil = Oil()
        pan.add_oil(oil)
        pan.heat_oil()
        egg = Egg()
        egg.break_egg()
        pan.add_ingredient(egg)
        pan.fry()
        self.assertEqual(egg.state, EggState.FRYING)

    def test_fry_no_egg(self):
        stove = Stove()
        stove.turn_on()
        pan = Pan(stove)
        pan.heat()  
        pan.heat()  
        oil = Oil()
        pan.add_oil(oil)
        pan.heat_oil()
        with self.assertRaises(ValueError):
            pan.fry()

    def test_fry_burnt(self):
        stove = Stove()
        stove.turn_on()
        pan = Pan(stove)
        pan.heat() 
        pan.heat()  
        oil = Oil()
        pan.add_oil(oil)
        pan.heat_oil()
        egg = Egg()
        egg.break_egg()
        pan.add_ingredient(egg)
        for _ in range(4):
            pan.fry()
        self.assertEqual(egg.state, EggState.BURNT)

class TestPanMix(unittest.TestCase):
    def test_mix_success(self):
        stove = Stove()
        stove.turn_on()
        pan = Pan(stove)
        pan.heat() 
        pan.heat()  
        oil = Oil()
        pan.add_oil(oil)
        pan.heat_oil()
        egg = Egg()
        egg.break_egg()
        pan.add_ingredient(egg)
        pan.fry()
        spatula = Spatula()
        pan.mix(spatula)
        self.assertTrue(pan.mixed)
        self.assertEqual(spatula.state, SpatulaState.USED)

    def test_mix_no_fry(self):
        stove = Stove()
        pan = Pan(stove)
        spatula = Spatula()
        with self.assertRaises(ValueError):
            pan.mix(spatula)

class TestPanTransferToDish(unittest.TestCase):
    def test_transfer_success(self):
        stove = Stove()
        stove.turn_on()
        pan = Pan(stove)
        pan.heat() 
        pan.heat()  
        oil = Oil()
        pan.add_oil(oil)
        pan.heat_oil()
        egg = Egg()
        egg.break_egg()
        pan.add_ingredient(egg)
        pan.fry()
        pan.fry()
        pan.fry()
        dish = Dish()
        pan.transfer_to_dish(dish)
        self.assertEqual(dish.contents, "Глазунья")

    def test_transfer_burnt(self):
        stove = Stove()
        stove.turn_on()
        pan = Pan(stove)
        pan.heat()  
        pan.heat()  
        oil = Oil()
        pan.add_oil(oil)
        pan.heat_oil()
        egg = Egg()
        egg.break_egg()
        pan.add_ingredient(egg)
        for _ in range(4):
            pan.fry()
        dish = Dish()
        pan.transfer_to_dish(dish)
        self.assertEqual(dish.contents, "Сгоревшая яичница")

    def test_transfer_not_cooked(self):
        stove = Stove()
        stove.turn_on()
        pan = Pan(stove)
        pan.heat()  
        pan.heat() 
        oil = Oil()
        pan.add_oil(oil)
        pan.heat_oil()
        egg = Egg()
        egg.break_egg()
        pan.add_ingredient(egg)
        dish = Dish()
        with self.assertRaises(ValueError):
            pan.transfer_to_dish(dish)

if __name__ == '__main__':
    unittest.main()
