import json
from datetime import datetime
from enum import Enum
from typing import List, Dict


class OrderState:
    def prepare(self, order: 'Order') -> 'OrderState':
        return self

    def deliver(self, order: 'Order') -> 'OrderState':
        return self

    def complete(self, order: 'Order') -> 'OrderState':
        return self

    def __str__(self):
        return self.__class__.__name__


class NewOrder(OrderState):
    def prepare(self, order: 'Order') -> 'OrderState':
        print(f"Заказ #{order.order_id} принят, начинаем готовить: {', '.join(order.items)}")
        return CookingOrder()


class CookingOrder(OrderState):
    def deliver(self, order: 'Order') -> 'OrderState':
        print(f"Пицца {', '.join(order.items)} приготовлена, передаем курьеру")
        return DeliveringOrder()


class DeliveringOrder(OrderState):
    def complete(self, order: 'Order') -> 'OrderState':
        print(f"Заказ #{order.order_id} с пиццами {', '.join(order.items)} успешно доставлен")
        return CompletedOrder()


class Order:
    def __init__(self, order_id: int, client: 'Client', items: List[str]):
        self.order_id = order_id
        self.client = client
        self.items = items
        self._state: OrderState = NewOrder()
        self.created_at = datetime.now()
        self.price: float = 0.0

    @property
    def state(self) -> OrderState:
        return self._state

    @state.setter
    def state(self, state: OrderState):
        self._state = state

    def prepare(self):
        self._state = self._state.prepare(self)

    def deliver(self):
        self._state = self._state.deliver(self)

    def complete(self):
        self._state = self._state.complete(self)


class CompletedOrder(OrderState):
    pass


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
        self._name = name

    @property
    def name(self):
        return self._name

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
    def __init__(self, toppings: List[Topping], dough: Dough, bake: Bake, name: str, price: float):
        self._name_to_pizza = name
        self._price = price
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


class Accounting:
    def __init__(self):
        self._income: float = 0.0

    def add_income(self, amount: float):
        self._income += amount

    @property
    def income(self):
        return self._income

    @property
    def profit(self):
        return self._income


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

    @property
    def phone_num(self):
        return self._phone_num

    @phone_num.setter
    def phone_num(self, value: str):
        self._phone_num = value


class Client(User):
    def __init__(self, address: str):
        super().__init__(User.Role.CLIENT)
        self._address = address
        self._orders: List[Order] = []

    @property
    def address(self):
        return self._address

    def create_order(self, order: Order):
        self._orders.append(order)
        print(f"Order #{order.order_id} created")


class Courier(User):
    def __init__(self):
        super().__init__(User.Role.COURIER)
        self._transport = ""

    @property
    def transport(self):
        return self._transport

    @transport.setter
    def transport(self, value: str):
        self._transport = value

    def deliver_order(self, order: Order):
        if not isinstance(order.state, CookingOrder):
            print("Заказ еще не готов к доставке")
            return

        order.deliver()
        if isinstance(order.state, DeliveringOrder):
            order.complete()
        print(f"Order #{order.order_id} delivered")


class Chef(User):
    def __init__(self):
        super().__init__(User.Role.KITCHENER)
        self._toppings: List[Topping] = []
        self._dough = None
        self._bake = None

    @property
    def toppings(self):
        return self._toppings

    @toppings.setter
    def toppings(self, value: List[Topping]):
        self._toppings = value

    @property
    def dough(self):
        return self._dough

    @dough.setter
    def dough(self, value: Dough):
        self._dough = value

    @property
    def bake(self):
        return self._bake

    @bake.setter
    def bake(self, value: Bake):
        self._bake = value

    def prepare_pizza(self, order: Order):
        if not isinstance(order.state, NewOrder):
            raise ValueError("Заказ не в состоянии для приготовления")

        if not self.dough or not self.toppings or not self.bake:
            raise ValueError("Не хватает ингредиентов для приготовления")

        pizza = Pizza(self.toppings, self.dough, self.bake, name=order.items[0], price=order.price)
        order.prepare()
        return pizza


class Pizzeria:
    def __init__(self):
        self._orders: Dict[int, Order] = {}
        self._accounting = Accounting()
        self._next_order_id = 1
        self._menu = {}

    @property
    def menu(self):
        return self._menu

    @menu.setter
    def menu(self, value: Dict[str, float]):
        if not isinstance(value, dict):
            raise ValueError("Menu должно быть словарем.")

        for item, price in value.items():
            if not isinstance(item, str) or not isinstance(price, (int, float)):
                raise ValueError("Ключи должны быть строками, а значения — числами.")

        self._menu = value

    @property
    def accounting(self):
        return self._accounting

    @property
    def orders(self):
        return self._orders

    @property
    def next_order_id(self):
        return self._next_order_id

    @next_order_id.setter
    def next_order_id(self, value: int):
        self._next_order_id = value

    @property
    def total_income(self):
        return self._accounting.income

    def update_income(self, income_data: Dict[str, float]):
        if "income" in income_data:
            self._accounting.add_income(income_data["income"])
        else:
            print("Ключ 'income' не найден в данных.")

    def load_menu(self):
        with open('menu.json', 'r', encoding='utf-8') as file:
            menu_items = json.load(file)
            self.menu = {item['name']: item['price'] for item in menu_items}

    def accept_order(self, client: Client):
        if not self.menu:
            self.load_menu()

        print("Меню:")
        menu_items = list(self.menu.keys())
        for idx, item in enumerate(menu_items, 1):
            print(f"{idx}. {item} - {self.menu[item]} руб.")

        selected_items = []
        while True:
            choice = input("Введите номер пиццы (или 'done' для завершения): ")

            if choice.lower() == 'done':
                if not selected_items:
                    print("Вы не выбрали ни одной пиццы. Пожалуйста, выберите хотя бы одну.")
                    continue
                break

            try:
                index = int(choice) - 1
                if index < 0 or index >= len(menu_items):
                    raise ValueError("Неверный номер пиццы.")
                selected_items.append(menu_items[index])
            except ValueError as e:
                print(f"Ошибка: {e}")

        order = Order(self.next_order_id, client, selected_items)
        order.price = sum(self.menu[item] for item in selected_items)
        self.orders[order.order_id] = order
        self.next_order_id += 1
        self.accounting.add_income(order.price)
        return order

    def serve_customer(self, client: Client):
        order = self.accept_order(client)
        client.create_order(order)


class ConsoleApp:
    def __init__(self):
        self.pizzeria = Pizzeria()
        self.clients = []
        self.chefs = []
        self.couriers = []
        self.current_order = None
        self.load_data()

    def save_data(self):
        try:
            with open("data.json", "r") as f:
                existing_data = json.load(f)
        except FileNotFoundError:
            existing_data = {
                "clients": [],
                "chefs": [],
                "couriers": [],
                "orders": [],
                "finances": {"income": 0.0},
                "last_order_id": 0
            }

        new_data = {
            "clients": [{"name": client.name, "address": client.address, "phone": client.phone_num}
                        for client in self.clients],
            "chefs": [{"name": chef.name} for chef in self.chefs],
            "couriers": [{"name": courier.name, "transport": courier.transport}
                         for courier in self.couriers],
            "orders": [{
                "order_id": order.order_id,
                "client": order.client.name,
                "items": order.items,
                "state": order.state.__class__.__name__
            } for order in self.pizzeria.orders.values()],
            "finances": {
                "income": self.pizzeria.total_income,
            },
            "last_order_id": self.pizzeria.next_order_id
        }

        with open("data.json", "w") as f:
            json.dump(new_data, f, indent=4)
        print("Данные сохранены!")

    def load_data(self):
        try:
            with open("data.json", "r") as f:
                data = json.load(f)

                state_classes = {
                    'NewOrder': NewOrder,
                    'CookingOrder': CookingOrder,
                    'DeliveringOrder': DeliveringOrder,
                    'CompletedOrder': CompletedOrder
                }

                for client_data in data["clients"]:
                    client = Client(client_data["address"])
                    client.name = client_data["name"]
                    client.phone_num = client_data["phone"]
                    self.clients.append(client)

                for chef_data in data["chefs"]:
                    chef = Chef()
                    chef.name = chef_data["name"]
                    self.chefs.append(chef)

                for courier_data in data["couriers"]:
                    courier = Courier()
                    courier.name = courier_data["name"]
                    courier.transport = courier_data["transport"]
                    self.couriers.append(courier)

                for order_data in data["orders"]:
                    client = next((c for c in self.clients if c.name == order_data["client"]), None)
                    if client:
                        order = Order(order_data["order_id"], client, order_data["items"])
                        state_class = state_classes.get(order_data["state"], NewOrder)
                        order.state = state_class()
                        self.pizzeria.orders[order.order_id] = order

                self.pizzeria.update_income(data["finances"])
                self.pizzeria.next_order_id = data.get("last_order_id", 0) + 1

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
        while True:
            phone = input("Номер телефона: ")
            if phone.isdigit() and len(phone) == 8:
                print(f"ok:  {phone}")
                break
            else:
                print("Ошибка: телефон должен содержать только 8 цифр")
        client = Client(address)
        client.name = name
        client.phone_num = phone
        self.clients.append(client)
        self.save_data()
        print(f"Клиент {name} создан")

    def create_kitchener(self):
        name = input("Имя повара: ")
        kitchener = Chef()
        kitchener.name = name
        self.chefs.append(kitchener)
        self.save_data()
        print(f"Повар {name} создан")

    def create_courier(self):
        name = input("Имя курьера: ")
        transport = input("Транспорт: ")
        courier = Courier()
        courier.name = name
        courier.transport = transport
        self.couriers.append(courier)
        self.save_data()
        print(f"Курьер {name} создан")

    def create_order(self):
        if not self.clients:
            print("Нет клиентов!")
            return

        print("Доступные клиенты:")
        for i, client in enumerate(self.clients, 1):
            print(f"{i}. {client.name}")

        client_idx = int(input("Выберите клиента: ")) - 1
        if client_idx < 0 or client_idx >= len(self.clients):
            print("Неверный выбор клиента!")
            return

        client = self.clients[client_idx]

        self.current_order = self.pizzeria.accept_order(client)
        if self.current_order:
            client.create_order(self.current_order)
            self.current_order.state = NewOrder()
            self.save_data()
            print(f"Заказ #{self.current_order.order_id} создан")

    def prepare_pizza(self):
        preparing_orders = [order for order in self.pizzeria.orders.values() if isinstance(order.state, NewOrder)]

        if not preparing_orders:
            print("Нет новых заказов для приготовления!")
            return

        print("Доступные заказы для приготовления:")
        for i, order in enumerate(preparing_orders, 1):
            print(f"{i}. Заказ #{order.order_id} от клиента {order.client.name}")

        try:
            order_idx = int(input("Выберите номер заказа для приготовления: ")) - 1
            if order_idx < 0 or order_idx >= len(preparing_orders):
                print("Неверный выбор")
                return

            selected_order = preparing_orders[order_idx]

            if not isinstance(selected_order.state, NewOrder):
                print("Заказ уже готовится или готов!")
                return

            chef = self.chefs[0] if self.chefs else None
            if not chef:
                print("Нет доступных поваров!")
                return

            chef.dough = Dough(Dough.TypeOfDough.THIN)
            chef.toppings = [Topping("сыр"), Topping("томаты")]
            chef.bake = Bake(200)

            pizza = chef.prepare_pizza(selected_order)
            print(f"Пицца приготовлена: {pizza}")
            self.save_data()
        except ValueError:
            print("Ошибка: введите номер заказа.")
        except Exception as e:
            print(f"Ошибка при приготовлении: {e}")

    def deliver_order(self):
        delivering_orders = [order for order in self.pizzeria.orders.values() if
                             isinstance(order.state, CookingOrder)]

        if not delivering_orders:
            print("Нет заказов, готовящихся к доставке!")
            return

        print("Доступные заказы для доставки:")
        for i, order in enumerate(delivering_orders, 1):
            print(f"{i}. Заказ #{order.order_id} от клиента {order.client.name}")

        try:
            order_idx = int(input("Выберите номер заказа для доставки: ")) - 1
            if order_idx < 0 or order_idx >= len(delivering_orders):
                print("Неверный выбор")
                return

            selected_order = delivering_orders[order_idx]

            courier = self.couriers[0] if self.couriers else None
            if not courier:
                print("Нет доступных курьеров!")
                return

            courier.deliver_order(selected_order)
            self.save_data()
            print(f"Заказ #{selected_order.order_id} доставлен")
        except ValueError:
            print("Ошибка: введите номер заказа.")

    def show_finance(self):
        profit = self.pizzeria.total_income
        print(f"\nТекущая прибыль: {profit} руб.")


if __name__ == "__main__":
    app = ConsoleApp()
    app.run()
