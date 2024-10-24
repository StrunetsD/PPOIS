// MechanicsDesignerTest.cpp
#include "../src/MechanicsDesigner.h"
#include <gtest/gtest.h>

class MechanicsDesignerTest : public ::testing::Test {
protected:
    MechanicsDesigner* mechanicsDesigner;

    void SetUp() override {
        mechanicsDesigner = new MechanicsDesigner("Eve", 30, 60000.0);
    }

    void TearDown() override {
        delete mechanicsDesigner;
    }
};

TEST_F(MechanicsDesignerTest, DesignMechanicsTest) {
    testing::internal::CaptureStdout();
    mechanicsDesigner->designMechanics();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "Eve is designing game mechanics.\n");
}

TEST_F(MechanicsDesignerTest, BalanceGameMechanicsTest) {
    testing::internal::CaptureStdout();
    mechanicsDesigner->balanceGameMechanics();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "Eve is balancing game mechanics.\n");
}

TEST_F(MechanicsDesignerTest, CreateCombatSystemTest) {
    testing::internal::CaptureStdout();
    mechanicsDesigner->createCombatSystem();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "Eve is creating a combat system.\n");
}
