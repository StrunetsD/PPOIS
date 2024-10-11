#include "../cmake-build-debug/Event.h"
#include "gtest/gtest.h"

class EventTest : public ::testing::Test {
protected:
    Event* event= new Event("Birthday Party","2023-12-01");
};

TEST_F(EventTest, GetName) {
    EXPECT_EQ(event->getName(), "Birthday Party");
}

TEST_F(EventTest, GetDate) {
    EXPECT_EQ(event->getDate(), "2023-12-01");
}


TEST_F(EventTest, GetId) {

    EXPECT_GT(event->getId(), 0);
}

TEST_F(EventTest, ShowInfo) {
    testing::internal::CaptureStdout();
    event->showInfo();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("name: Birthday Party"), string::npos);
    EXPECT_NE(output.find("date:  2023-12-01"), string::npos);
    EXPECT_NE(output.find("id:  "), string::npos);
}
