#include "gtest/gtest.h"
#include "../cmake-build-debug/Transaction.h"


class TransactionTest : public ::testing::Test {
protected:
        Artist* artist_ = new Artist("Van Gog","try killed hi,self");
        Category* category_ = new Category("post-impressionism");
        Client* client_ = new Client("Maksim","@example.com","1111");
        Painting* painting_ = new Painting("Starry Night",artist_,"post-impressionism",10000,category_);
        Transaction* transaction_ = new Transaction(client_,painting_,10000);

};


TEST_F(TransactionTest, ProcessTransaction) {
    testing::internal::CaptureStdout();
    transaction_->process();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "Processing transaction: Maksim bought Starry Night for 10000 $.\n");
}

// Тестируем метод getAmount
TEST_F(TransactionTest, GetAmount) {
    EXPECT_EQ(transaction_->getAmount(), 10000);
}

