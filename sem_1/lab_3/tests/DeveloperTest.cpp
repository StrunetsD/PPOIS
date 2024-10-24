// DeveloperTest.cpp
#include "../src/Developer.h"
#include <gtest/gtest.h>

class DeveloperTest : public ::testing::Test {
protected:
    Developer* developer;

    void SetUp() override {
        developer = new Developer("Bob", 32, 60000.0);
    }

    void TearDown() override {
        delete developer;
    }
};

TEST_F(DeveloperTest, DevelopGameTest) {
    testing::internal::CaptureStdout();
    developer->developGame();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "Bob is developing game code.\n");
}

TEST_F(DeveloperTest, FixBugsTest) {
    testing::internal::CaptureStdout();
    developer->fixBugs();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "Bob is fixing bugs.\n");
}
