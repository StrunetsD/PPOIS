// BankTest.cpp
#include "../src/Bank.h"
#include "../src/Transaction.h"
#include <gtest/gtest.h>

class BankTest : public ::testing::Test {
protected:
    Bank* bank;

    void SetUp() override {
        bank = new Bank("Test Bank", 1000.0);
    }

    void TearDown() override {
        delete bank;
    }
};

TEST_F(BankTest, InitialBalanceTest) {
    EXPECT_EQ(bank->getBalance(), 1000.0);
}

TEST_F(BankTest, DepositTest) {
    Transaction deposit("deposit", 500.0);
    bank->addTransaction(deposit);

    EXPECT_EQ(bank->getBalance(), 1500.0);
}

TEST_F(BankTest, WithdrawalTest) {
    Transaction withdrawal("withdrawal", 300.0);
    bank->addTransaction(withdrawal);

    EXPECT_EQ(bank->getBalance(), 700.0);
}

TEST_F(BankTest, InsufficientFundsTest) {
    Transaction withdrawal("withdrawal", 1200.0);

    EXPECT_THROW(bank->addTransaction(withdrawal), std::runtime_error);
}

TEST_F(BankTest, NegativeInitialBalanceTest) {
    EXPECT_THROW(new Bank("Test Bank", -500.0), std::invalid_argument);
}

TEST_F(BankTest, TransactionHistoryTest) {
    Transaction deposit("deposit", 200.0);
    Transaction withdrawal("withdrawal", 100.0);
    bank->addTransaction(deposit);
    bank->addTransaction(withdrawal);

    testing::internal::CaptureStdout();
    bank->displayTransactions();
    std::string output = testing::internal::GetCapturedStdout();

    std::string expectedOutput = "Transaction history for bank: Test Bank\n"
                                  "Type: deposit, Amount: 200\n"
                                  "Type: withdrawal, Amount: 100\n";

    EXPECT_EQ(output, expectedOutput); // Проверка вывода
}
