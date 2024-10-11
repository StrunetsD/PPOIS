#include "../cmake-build-debug/Bank.h"
#include "gtest/gtest.h"





class TransactionMock : public Transaction {
public:
    TransactionMock(Client* client, Painting* painting, double amount)
        : Transaction(client, painting, amount) {}

    void process() const {
        Transaction::process();
    }
};


class BankTest : public ::testing::Test {
protected:
    Bank bank;
};


TEST_F(BankTest, ProcessTransaction) {
    Artist* artist_ = new Artist("Van Gog","try killed hi,self");
    Category* category_ = new Category("post-impressionism");
    Client* client_ = new Client("Maksim","@example.com","1111");
    Painting* painting_ = new Painting("Starry Night",artist_,"post-impressionism",0,category_);
    Transaction* transaction_ = new Transaction(client_,painting_,0);
    bank.processTransaction(transaction_);
    EXPECT_EQ(bank.getTotalRevenue(), 20);
}

TEST_F(BankTest, MultipleTransactions) {
    Artist* artist_ = new Artist("Van Gog","try killed hi,self");
    Category* category_ = new Category("post-impressionism");
    Client* client_ = new Client("Maksim","@example.com","1111");
    Painting* painting_ = new Painting("Starry Night",artist_,"post-impressionism",10000,category_);
    TransactionMock transaction1(client_, painting_, 10000);
    bank.processTransaction(&transaction1);

    EXPECT_EQ(bank.getTotalRevenue(), 10020); // 100 + 50 = 150
}


TEST_F(BankTest, NoTransactions) {
    EXPECT_EQ(bank.getTotalRevenue(), 20.0);
}



