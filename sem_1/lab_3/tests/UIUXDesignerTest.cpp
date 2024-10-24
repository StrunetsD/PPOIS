// UIUXDesignerTest.cpp
#include "../src/UIUXDesigner.h"
#include <gtest/gtest.h>

class UIUXDesignerTest : public ::testing::Test {
protected:
    UIUXDesigner* uiuxDesigner;

    void SetUp() override {
        uiuxDesigner = new UIUXDesigner("Charlie", 29, 55000.0);
    }

    void TearDown() override {
        delete uiuxDesigner;
    }
};

TEST_F(UIUXDesignerTest, DesignUITest) {
    testing::internal::CaptureStdout();
    uiuxDesigner->designUI();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "Charlie is designing the user interface.\n");
}

TEST_F(UIUXDesignerTest, CreateUXFlowTest) {
    testing::internal::CaptureStdout();
    uiuxDesigner->createUXFlow();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "Charlie is creating the user experience flow.\n");
}

TEST_F(UIUXDesignerTest, ConductUserTestingTest) {
    testing::internal::CaptureStdout();
    uiuxDesigner->conductUserTesting();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "Charlie is conducting user testing for UI/UX.\n");
}
