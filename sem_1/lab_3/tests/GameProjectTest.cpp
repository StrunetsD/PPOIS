// GameProjectTest.cpp
#include "../src/GameProject.h"
#include "../src/ProjectManager.h"
#include "../src/Employee.h"
#include <gtest/gtest.h>


class GameProjectTest : public ::testing::Test {
protected:
    ProjectManager* projectManager;
    GameProject* gameProject;

    void SetUp() override {
        projectManager = new ProjectManager("Alice", 35, 70000.0);
        gameProject = new GameProject("Epic Adventure", *projectManager);
    }

    void TearDown() override {
        delete gameProject;
        delete projectManager;
    }
};

TEST_F(GameProjectTest, GetTitleTest) {
    EXPECT_EQ(gameProject->getTitle(), "Epic Adventure");
}

TEST_F(GameProjectTest, StartDevelopmentTest) {
    testing::internal::CaptureStdout();
    gameProject->startDevelopment();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "Starting development of the game: Epic Adventure\nAlice is managing the project.\n");
}

TEST_F(GameProjectTest, ReleaseGameTest) {
    testing::internal::CaptureStdout();
    gameProject->releaseGame();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "The game Epic Adventure is released!\n");
}
