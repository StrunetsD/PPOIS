// QATest.cpp
#include "../src/QA.h"
#include <gtest/gtest.h>

class QATest : public ::testing::Test {
protected:
    QA* qaTester;

    void SetUp() override {
        qaTester = new QA("Lisa", 28, 45000.0);
    }

    void TearDown() override {
        delete qaTester;
    }
};

TEST_F(QATest, TestGameTest) {
    testing::internal::CaptureStdout();
    qaTester->testGame();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "Lisa is testing the game.\n");
}

TEST_F(QATest, WriteTestCasesTest) {
    testing::internal::CaptureStdout();
    qaTester->writeTestCases();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "Lisa is writing test cases.\n");
}
