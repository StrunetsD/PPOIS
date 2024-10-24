// AIEngineerTest.cpp
#include "../src/AIEngineer.h"
#include <gtest/gtest.h>

class AIEngineerTest : public ::testing::Test {
protected:
    AIEngineer* aiEngineer;

    void SetUp() override {
        aiEngineer = new AIEngineer("David", 33, 65000.0);
    }

    void TearDown() override {
        delete aiEngineer;
    }
};

TEST_F(AIEngineerTest, DevelopAITest) {
    testing::internal::CaptureStdout();
    aiEngineer->developAI();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "David is developing AI for NPCs.\n");
}

TEST_F(AIEngineerTest, SetAIPatrolRoutesTest) {
    testing::internal::CaptureStdout();
    aiEngineer->setAIPatrolRoutes();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "David is setting patrol routes for AI.\n");
}

TEST_F(AIEngineerTest, ImproveAITest) {
    testing::internal::CaptureStdout();
    aiEngineer->improveAI();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "David is improving AI behavior.\n");
}
