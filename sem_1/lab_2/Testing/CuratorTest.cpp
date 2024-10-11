#include "gtest/gtest.h"
#include "../cmake-build-debug/Curator.h"
#include <memory>
#include <string>

class CuratorTest : public ::testing::Test {
protected:
    Curator* curator = new Curator("Kirill", "10:00");
};

TEST_F(CuratorTest, WorkMethodOutputsCorrectMessage) {
    testing::internal::CaptureStdout();
    curator->work();
    std::string output = testing::internal::GetCapturedStdout();
    std::string expected = "Curator Kirill arrived in 10:00 and work.\n";
    EXPECT_EQ(output, expected);
}