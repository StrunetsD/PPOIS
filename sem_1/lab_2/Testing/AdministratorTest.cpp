#include "../cmake-build-debug/Administrator.h"
#include "gtest/gtest.h"



class AdministratorTest : public ::testing::Test {
protected:
    Administrator* admin = new Administrator("Kirill", "10:00");
};
TEST_F(AdministratorTest, WorkMethodOutputsCorrectMessage) {
    testing::internal::CaptureStdout();
    admin->work();
    string output = testing::internal::GetCapturedStdout();
    string expected = "Administrator Kirill arrived in 10:00 and work.\n";
    EXPECT_EQ(output, expected);
}