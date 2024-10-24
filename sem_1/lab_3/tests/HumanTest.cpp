#include <gtest/gtest.h>
#include "../src/Human.h"


class TestHuman : public Human {
public:
    TestHuman(const string& name, int age) : Human(name, age) {}
    void work() const override {
    }
};


class HumanTest : public ::testing::Test {
protected:
    TestHuman* human{};

    void SetUp() override {
        human = new TestHuman("Alice", 25);
    }

    void TearDown() override {
        delete human;
    }
};

TEST_F(HumanTest, GetName) {
    EXPECT_EQ(human->getName(), "Alice");
}

TEST_F(HumanTest, GetAge) {
    EXPECT_EQ(human->getAge(), 25);
}
