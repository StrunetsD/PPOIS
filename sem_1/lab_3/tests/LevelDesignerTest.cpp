// LevelDesignerTest.cpp
#include "../src/LevelDesigner.h"
#include <gtest/gtest.h>

class LevelDesignerTest : public ::testing::Test {
protected:
    LevelDesigner* levelDesigner;

    void SetUp() override {
        levelDesigner = new LevelDesigner("Charlie", 29, 50000.0);
    }

    void TearDown() override {
        delete levelDesigner;
    }
};

TEST_F(LevelDesignerTest, DesignLevelTest) {
    testing::internal::CaptureStdout();
    levelDesigner->designLevel();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "Charlie is designing a new level.\n");
}

TEST_F(LevelDesignerTest, PlaceObjectsTest) {
    testing::internal::CaptureStdout();
    levelDesigner->placeObjects();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "Charlie is placing objects in the level.\n");
}
