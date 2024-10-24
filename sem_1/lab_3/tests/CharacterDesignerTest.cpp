#include "../src/CharacterDesigner.h"
#include <gtest/gtest.h>

class CharacterDesignerTest : public ::testing::Test {
protected:
    CharacterDesigner* characterDesigner;

    void SetUp() override {
        characterDesigner = new CharacterDesigner("Alice", 28, 55000.0);
    }

    void TearDown() override {
        delete characterDesigner;
    }
};

TEST_F(CharacterDesignerTest, DesignCharacterTest) {
    std::string characterName = "Hero";
    testing::internal::CaptureStdout();
    characterDesigner->designCharacter(characterName);
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "Alice is designing character: Hero\n");
}

TEST_F(CharacterDesignerTest, ChooseAppearanceTest) {
    testing::internal::CaptureStdout();
    characterDesigner->chooseAppearance();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "Alice is choosing character appearance.\n");
}

TEST_F(CharacterDesignerTest, AssignWeaponTest) {
    std::string weapon = "Sword";
    testing::internal::CaptureStdout();
    characterDesigner->assignWeapon(weapon);
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "Alice assigned weapon: Sword\n");
}
