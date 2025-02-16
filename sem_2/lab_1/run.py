import json
from datetime import datetime
from enum import Enum
from typing import List, Dict


class Dough:
    class TypeOfDough(Enum):
        THICK = 'thick'
        THIN = 'thin'

    def __init__(self, dough_type: TypeOfDough):
        if not isinstance(dough_type, self.TypeOfDough):
            raise ValueError("Invalid dough type")
        self._dough_type = dough_type

    @property
    def dough_type(self):
        return self._dough_type

    def prepare(self):
        print(f"Preparing {self.dough_type.value} dough")

    def __str__(self):
        return self.dough_type.value


class Topping:
    def __init__(self, name: str):
        if not name:
            raise ValueError("Topping name required")
        self.name = name

    def __str__(self):
        return self.name


class Bake:
    def __init__(self, temperature: float = 200):
        if temperature < 0:
            raise ValueError("Invalid temperature")
        self._temperature = temperature

    @property
    def temperature(self):
        return self._temperature

    def __str__(self):
        return f"Baking at {self.temperature}°C"


class Pizza:
    def __init__(self, toppings: List[Topping], dough: Dough, bake: Bake):
        if not toppings:
            raise ValueError("Toppings required")
        self._toppings = toppings
        self._dough = dough
        self._bake = bake

    @property
    def toppings(self):
        return self._toppings

    @property
    def dough(self):
        return self._dough

    def __str__(self):
        return f"Pizza with {len(self.toppings)} toppings"


class Order:
    class Status(Enum):
        NEW = "new"
        COOKING = "cooking"
        DELIVERING = "delivering"
        COMPLETED = "completed"

    def __init__(self, order_id: int, client: 'Client', items: List[str]):
        self.order_id = order_id
        self.client = client
        self.items = items
        self.status = self.Status.NEW
        self.created_at = datetime.now()
        self.price: float = 0.0


class Accounting:
    def __init__(self):
        self._income: float = 0.0
        self._expenses: float = 0.0

    def add_income(self, amount: float):
        self._income += amount

    def add_expense(self, amount: float):
        self._expenses += amount

    @property
    def profit(self):
        return self._income - self._expenses


class User:
    class Role(Enum):
        ADMIN = 'admin'
        CLIENT = 'client'
        COURIER = 'courier'
        KITCHENER = 'kitchener'

    def __init__(self, role: Role):
        self._name = ""
        self._gender = ""
        self._role = role
        self._phone_num = ""

    @property
    def name(self):
        return self._name

    @name.setter
    def name(self, value: str):
        self._name = value

    @property
    def role(self):
        return self._role


class Client(User):
    def __init__(self, address: str):
        super().__init__(User.Role.CLIENT)
        self._address = address
        self._orders: List[Order] = []

    def create_order(self, order: Order):
        self._orders.append(order)
        print(f"Order #{order.order_id} created")


class Courier(User):
    def __init__(self):
        super().__init__(User.Role.COURIER)
        self._transport = ""

    def deliver_order(self, order: Order):
        order.status = Order.Status.COMPLETED
        print(f"Order #{order.order_id} delivered")


class Kitchener(User):
    def __init__(self):
        super().__init__(User.Role.KITCHENER)
        self._toppings: List[Topping] = []
        self._dough = None
        self._bake = None

    def prepare_pizza(self, order: Order):
        pizza = Pizza(self._toppings, self._dough, self._bake)
        order.status = Order.Status.COOKING
        return pizza


class Pizzeria:
    def __init__(self):
        self._orders: Dict[int, Order] = {}
        self._menu = {"Margherita": 12.99, "Pepperoni": 14.99}
        self._accounting = Accounting()
        self._next_order_id = 1

    def accept_order(self, client: Client, items: List[str]):
        order = Order(self._next_order_id, client, items)
        order.price = sum(self._menu[item] for item in items)
        self._orders[order.order_id] = order
        self._next_order_id += 1
        self._accounting.add_income(order.price)
        return order

    def serve_customer(self, client: Client, items: List[str]):
        order = self.accept_order(client, items)
        client.create_order(order)


class ConsoleApp:
    def __init__(self):
        self.pizzeria = Pizzeria()
        self.clients = []
        self.kitcheners = []
        self.couriers = []
        self.current_order = None
        self.load_data()  # Загружаем данные при запуске

    def save_data(self):
        data = {
            "clients": [{"name": client.name, "address": client._address, "phone": client._phone_num} for client in
                        self.clients],
            "orders": [{"order_id": order.order_id, "client": order.client.name, "items": order.items,
                        "status": order.status.value} for order in self.pizzeria._orders.values()],
            "finances": {"income": self.pizzeria._accounting._income, "expenses": self.pizzeria._accounting._expenses}
        }
        with open("data.json", "w") as f:
            json.dump(data, f, indent=4)
        print("Данные сохранены!")

    def load_data(self):
        try:
            with open("data.json", "r") as f:
                data = json.load(f)
                for client_data in data["clients"]:
                    client = Client(client_data["address"])
                    client.name = client_data["name"]
                    client._phone_num = client_data["phone"]
                    self.clients.append(client)

                for order_data in data["orders"]:
                    client = next((c for c in self.clients if c.name == order_data["client"]), None)
                    if client:
                        order = Order(order_data["order_id"], client, order_data["items"])
                        order.status = Order.Status[order_data["status"].upper()]
                        self.pizzeria._orders[order.order_id] = order

                self.pizzeria._accounting._income = data["finances"]["income"]
                self.pizzeria._accounting._expenses = data["finances"]["expenses"]

            print("Данные загружены!")
        except FileNotFoundError:
            print("Файл данных не найден. Будет создан новый файл.")
        except Exception as e:
            print(f"Ошибка при загрузке данных: {e}")

    def run(self):
        while True:
            print("\n1. Создать клиента")
            print("2. Создать повара")
            print("3. Создать курьера")
            print("4. Сделать заказ")
            print("5. Приготовить пиццу")
            print("6. Доставить заказ")
            print("7. Показать финансы")
            print("8. Выход")

            choice = input("Выберите действие: ")

            if choice == "1":
                self.create_client()
            elif choice == "2":
                self.create_kitchener()
            elif choice == "3":
                self.create_courier()
            elif choice == "4":
                self.create_order()
            elif choice == "5":
                self.prepare_pizza()
            elif choice == "6":
                self.deliver_order()
            elif choice == "7":
                self.show_finance()
            elif choice == "8":
                self.save_data()
                break
            else:
                print("Неверный выбор")

    def create_client(self):
        name = input("Имя клиента: ")
        address = input("Адрес: ")
        phone = input("Телефон: ")
        client = Client(address)
        client.name = name
        client._phone_num = phone
        self.clients.append(client)
        self.save_data()  # Сохраняем данные после создания клиента
        print(f"Клиент {name} создан")

    def create_kitchener(self):
        name = input("Имя повара: ")
        kitchener = Kitchener()
        kitchener.name = name
        self.kitcheners.append(kitchener)
        self.save_data()  # Сохраняем данные после создания повара
        print(f"Повар {name} создан")

    def create_courier(self):
        name = input("Имя курьера: ")
        transport = input("Транспорт: ")
        courier = Courier()
        courier.name = name
        courier._transport = transport
        self.couriers.append(courier)
        self.save_data()  # Сохраняем данные после создания курьера
        print(f"Курьер {name} создан")

    def create_order(self):
        if not self.clients:
            print("Нет клиентов!")
            return

        print("Доступные клиенты:")
        for i, client in enumerate(self.clients, 1):
            print(f"{i}. {client.name}")

        client_idx = int(input("Выберите клиента: ")) - 1
        client = self.clients[client_idx]

        print("Меню:", ", ".join(self.pizzeria._menu.keys()))
        items = input("Введите названия пицц через запятую: ").split(",")

        self.current_order = self.pizzeria.accept_order(client, items)
        client.create_order(self.current_order)
        self.save_data()  # Сохраняем данные после создания заказа
        print(f"Заказ #{self.current_order.order_id} создан")

    def prepare_pizza(self):
        if not self.current_order:
            print("Нет активного заказа!")
            return

        kitchener = self.kitcheners[0] if self.kitcheners else None
        if not kitchener:
            print("Нет доступных поваров!")
            return

        kitchener._dough = Dough(Dough.TypeOfDough.THIN)
        kitchener._toppings = [Topping("сыр"), Topping("томаты")]
        kitchener._bake = Bake(200)

        pizza = kitchener.prepare_pizza(self.current_order)
        print(f"Пицца приготовлена: {pizza}")
        self.current_order.status = Order.Status.COOKING
        self.save_data()

    def deliver_order(self):
        if not self.current_order:
            print("Нет активного заказа!")
            return

        courier = self.couriers[0] if self.couriers else None
        if not courier:
            print("Нет доступных курьеров!")
            return

        courier.deliver_order(self.current_order)
        self.save_data()  # Сохраняем данные после доставки заказа
        print(f"Заказ #{self.current_order.order_id} доставлен")

    def show_finance(self):
        profit = self.pizzeria._accounting.profit
        print(f"\nТекущая прибыль: {profit:.2f} руб.")


if __name__ == "__main__":
    app = ConsoleApp()
    app.run()