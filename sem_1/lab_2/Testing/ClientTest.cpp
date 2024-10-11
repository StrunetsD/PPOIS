#include "../cmake-build-debug/Client.h"
#include "gtest/gtest.h"


class ClientTest : public ::testing::Test {
protected:
    Client* client;

    void SetUp() override {
        // Инициализируем экземпляр Client с начальными параметрами
        client = new Client("Alice", "alice@example.com", "securePassword123");
    }

    void TearDown() override {
        delete client; // Освобождаем память
    }
};

// Тест на получение email
TEST_F(ClientTest, GetEmail) {
    EXPECT_EQ(client->getEmail(), "alice@example.com"); // Проверка, что email соответствует ожидаемому значению
}

// Тест на получение пароля
TEST_F(ClientTest, GetPassword) {
    EXPECT_EQ(client->getPassword(), "securePassword123"); // Проверка, что пароль соответствует ожидаемому
}




// Тест на отображение информации (можно использовать вывод в поток, но это не проверка на корректность)
TEST_F(ClientTest, ShowInfo) {
    testing::internal::CaptureStdout(); // Захват стандартного вывода
    client->showInfo(); // Вызов метода, который выводит информацию
    std::string output = testing::internal::GetCapturedStdout(); // Получение захваченного вывода

    EXPECT_NE(output.find("Name: Alice"), std::string::npos); // Проверка, что имя есть в выводе
    EXPECT_NE(output.find("Email: alice@example.com"), std::string::npos); // Проверка, что email есть в выводе
    EXPECT_NE(output.find("Password: securePassword123"), std::string::npos); // Проверка, что пароль есть в выводе
}