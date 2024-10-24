// SoundDesignerTest.cpp
#include "../src/SoundDesigner.h"
#include <gtest/gtest.h>

class SoundDesignerTest : public ::testing::Test {
protected:
    SoundDesigner* soundDesigner;

    void SetUp() override {
        soundDesigner = new SoundDesigner("Alex", 35, 70000.0);
    }

    void TearDown() override {
        delete soundDesigner;
    }
};

TEST_F(SoundDesignerTest, CreateSoundEffectsTest) {
    testing::internal::CaptureStdout();
    soundDesigner->createSoundEffects();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "Alex is creating sound effects.\n");
}

TEST_F(SoundDesignerTest, ComposeMusicTest) {
    testing::internal::CaptureStdout();
    soundDesigner->composeMusic();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "Alex is composing background music.\n");
}

TEST_F(SoundDesignerTest, AdjustAudioLevelsTest) {
    testing::internal::CaptureStdout();
    soundDesigner->adjustAudioLevels();
    std::string output = testing::internal::GetCapturedStdout();
}
