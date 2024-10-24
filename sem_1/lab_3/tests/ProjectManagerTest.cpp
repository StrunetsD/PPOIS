// ProjectManagerTest.cpp
#include "../src/ProjectManager.h"
#include <gtest/gtest.h>

class ProjectManagerTest : public ::testing::Test {
protected:
    ProjectManager* projectManager;

    void SetUp() override {
        projectManager = new ProjectManager("Alice", 40, 75000.0);
    }

    void TearDown() override {
        delete projectManager;
    }
};

TEST_F(ProjectManagerTest, ManageProjectTest) {
    testing::internal::CaptureStdout();
    projectManager->manageProject();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "Alice is managing the project.\n");
}

TEST_F(ProjectManagerTest, AllocateResourcesTest) {
    testing::internal::CaptureStdout();
    projectManager->allocateResources();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "Alice is allocating resources.\n");
}

TEST_F(ProjectManagerTest, MonitorProgressTest) {
    testing::internal::CaptureStdout();
    projectManager->monitorProgress();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "Alice is monitoring the project progress.\n");
}
