from run import *
from io import StringIO
from unittest.mock import patch
import unittest

class TestPizzeriaApp(unittest.TestCase):

    def setUp(self):
        self.app = ConsoleApp()
        self.app.clients = []
        self.app.chefs = []
        self.app.couriers = []
        self.app.pizzeria._next_order_id = 1

    def test_create_client(self):
        with patch('sys.stdout', new=StringIO()) as fake_out:
            with patch('builtins.input', side_effect=["Dima", "Minsk", "80297744702"]):
                self.app.create_client()
            self.assertIn("Клиент Dima создан", fake_out.getvalue())
            self.assertEqual(len(self.app.clients), 1)
            self.assertEqual(self.app.clients[0].name, "Dima")

    def test_create_chef(self):
        with patch('sys.stdout', new=StringIO()) as fake_out:
            with patch('builtins.input', side_effect=["Chef John"]):
                self.app.create_kitchener()
            self.assertIn("Повар Chef John создан", fake_out.getvalue())
            self.assertEqual(len(self.app.chefs), 1)
            self.assertEqual(self.app.chefs[0].name, "Chef John")

    def test_create_courier(self):
        with patch('sys.stdout', new=StringIO()) as fake_out:
            with patch('builtins.input', side_effect=["Courier Alex", "Bike"]):
                self.app.create_courier()
            self.assertIn("Курьер Courier Alex создан", fake_out.getvalue())
            self.assertEqual(len(self.app.couriers), 1)
            self.assertEqual(self.app.couriers[0].name, "Courier Alex")
            self.assertEqual(self.app.couriers[0]._transport, "Bike")

    def test_create_order(self):
        with patch('builtins.input', side_effect=["Dima", "Minsk", "80297744702"]):
            self.app.create_client()
        with patch('builtins.input', side_effect=["1", "Margherita"]):
            self.app.create_order()
        self.assertEqual(len(self.app.pizzeria._orders), 2)
        self.assertEqual(self.app.pizzeria._orders[1].client.name, "Dima")

    def test_prepare_pizza(self):
        with patch('builtins.input', side_effect=["Dima", "Minsk", "80297744702"]):
            self.app.create_client()
        with patch('builtins.input', side_effect=["1", "Margherita"]):
            self.app.create_order()
        with patch('builtins.input', side_effect=["Chef John"]):
            self.app.create_kitchener()

        with patch('sys.stdout', new=StringIO()) as fake_out:
            self.app.prepare_pizza()
            self.assertIn("Пицца приготовлена:", fake_out.getvalue())

    def test_deliver_order(self):
        with patch('builtins.input', side_effect=["Dima", "Minsk", "80297744702"]):
            self.app.create_client()
        with patch('builtins.input', side_effect=["1", "Margherita"]):
            self.app.create_order()
        with patch('builtins.input', side_effect=["Courier Alex", "Bike"]):
            self.app.create_courier()
        with patch('builtins.input', side_effect=["Chef John"]):
            self.app.create_kitchener()
        self.app.prepare_pizza()

        with patch('sys.stdout', new=StringIO()) as fake_out:
            self.app.deliver_order()
            self.assertIn("Заказ #1 доставлен", fake_out.getvalue())
            self.assertEqual(self.app.current_order.status, Order.Status.COMPLETED)

    def test_show_finance(self):
        with patch('builtins.input', side_effect=["Dima", "Minsk", "80297744702"]):
            self.app.create_client()
        with patch('builtins.input', side_effect=["1", "Margherita"]):
            self.app.create_order()
        self.app.pizzeria._accounting.add_income(12.99)
        with patch('sys.stdout', new=StringIO()) as fake_out:
            self.app.show_finance()
            self.assertIn("Текущая прибыль:", fake_out.getvalue())


if __name__ == "__main__":
    unittest.main()