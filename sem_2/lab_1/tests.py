import unittest
from run import *


class TestPizzeria(unittest.TestCase):
    def setUp(self):
        self.pizzeria = Pizzeria()
        self.client = Client("123 Main St")
        self.client.name = "John Doe"
        self.pizzeria.menu = {
            "Margherita": 500,
            "Pepperoni": 600
        }

    def test_order_state_transition(self):
        order = Order(1, self.client, ["Margherita"])
        self.assertIsInstance(order.state, NewOrder)

        order.prepare()
        self.assertIsInstance(order.state, CookingOrder)

        order.deliver()
        self.assertIsInstance(order.state, DeliveringOrder)

        order.complete()
        self.assertIsInstance(order.state, CompletedOrder)

    def test_dough_creation(self):
        dough = Dough(Dough.TypeOfDough.THIN)
        self.assertEqual(dough.dough_type, Dough.TypeOfDough.THIN)

    def test_topping_creation(self):
        topping = Topping("Cheese")
        self.assertEqual(topping.name, "Cheese")

    def test_pizza_creation(self):
        toppings = [Topping("Cheese"), Topping("Tomato")]
        dough = Dough(Dough.TypeOfDough.THIN)
        bake = Bake(200)
        pizza = Pizza(toppings, dough, bake, "Margherita", 500)

        self.assertEqual(pizza._name_to_pizza, "Margherita")
        self.assertEqual(len(pizza.toppings), 2)
        self.assertEqual(pizza.dough.dough_type, Dough.TypeOfDough.THIN)

    def test_accounting_income(self):
        accounting = self.pizzeria.accounting
        accounting.add_income(1000)
        self.assertEqual(accounting.income, 1000)

    def test_client_create_order(self):
        order = Order(1, self.client, ["Margherita"])
        self.client.create_order(order)
        self.assertIn(order, self.client._orders)

    def test_courier_deliver_order(self):
        order = Order(1, self.client, ["Margherita"])
        order.prepare()
        order.deliver()

        courier = Courier()
        courier.deliver_order(order)

        self.assertIsInstance(order.state, DeliveringOrder)


# Запуск тестов
if __name__ == "__main__":
    unittest.main()
