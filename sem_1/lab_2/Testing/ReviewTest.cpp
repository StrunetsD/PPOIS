#include <gtest/gtest.h>
#include "../cmake-build-debug/Review.h"

class ReviewTest : public ::testing::Test {
protected:
    Client* client = new Client("John Doe","@example.com","1111");
    Review* review = new Review(client,"Excellent service!",5);
};


TEST_F(ReviewTest, GetClientName) {
    EXPECT_EQ(review->getClientName(), "John Doe");
}


TEST_F(ReviewTest, GetContent) {
    EXPECT_EQ(review->getContent(), "Excellent service!");
}


TEST_F(ReviewTest, GetRating) {
    EXPECT_EQ(review->getRating(), 5);
}


TEST_F(ReviewTest, ShowInfo) {
    testing::internal::CaptureStdout();
    review->showInfo();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Review by: John Doe"), std::string::npos);
    EXPECT_NE(output.find("Rating: 5/5"), std::string::npos);
    EXPECT_NE(output.find("Comment: Excellent service!"), std::string::npos);
}




