#include "gtest/gtest.h"
#include "../cmake-build-debug/Security.h"


class SecurityTest : public ::testing::Test {
protected:
    Security*  security = new Security("Kirill", "10:00");

};
TEST_F(SecurityTest, WorkMethodOutputsCorrectMessage) {
    testing::internal::CaptureStdout();
    security->work();
    string output = testing::internal::GetCapturedStdout();
    string expected = "Security Kirill arrived in 10:00\n";
    EXPECT_EQ(output, expected);
}