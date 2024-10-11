#include "../cmake-build-debug/Workers.h"
#include "gtest/gtest.h"



class WorkersTest : public ::testing::Test {
protected:
    Workers* workers_ = new Workers;
    Administrator* administrator_ = new Administrator("Kirill","10:00");
    Curator* curator_ = new Curator("Masha","08:00");
    Security* security_ = new Security("Dima","04:00");

};


TEST_F(WorkersTest, AddAndRemoveAdministrators) {
    workers_->addAdministrator(administrator_);

    testing::internal::CaptureStdout();
    workers_->showAdministrators();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_TRUE(output.find("Kirill") != std::string::npos);


    workers_->removeAdministrator(administrator_);

    testing::internal::CaptureStdout();
    workers_->showAdministrators();
    std::string outputAfterRemoval = testing::internal::GetCapturedStdout();

    EXPECT_TRUE(outputAfterRemoval.find("Kirill") == std::string::npos);

}

TEST_F(WorkersTest, AddAndRemoveCurators) {
    workers_->addCurator(curator_);

    testing::internal::CaptureStdout();
    workers_->showCurators();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_TRUE(output.find("Masha") != std::string::npos);

    workers_->removeCurator(curator_);

    testing::internal::CaptureStdout();
    workers_->showCurators();
    std::string outputAfterRemoval = testing::internal::GetCapturedStdout();

    EXPECT_TRUE(outputAfterRemoval.find("Masha") == std::string::npos);
}


TEST_F(WorkersTest, AddAndRemoveSecurity) {
    workers_->addSecurity(security_);

    testing::internal::CaptureStdout();
    workers_->showSecurity();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_TRUE(output.find("Dima") != std::string::npos);

    workers_->removeSecurity(security_);

    testing::internal::CaptureStdout();
    workers_->showSecurity();
    std::string outputAfterRemoval = testing::internal::GetCapturedStdout();

    EXPECT_TRUE(outputAfterRemoval.find("Dima") == std::string::npos);
}

TEST_F(WorkersTest, ShowInfo) {
    workers_->addAdministrator(administrator_);
    workers_->addCurator(curator_);
    workers_->addSecurity(security_);

    testing::internal::CaptureStdout();
    workers_->showInfo();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_TRUE(output.find("Administrators") != std::string::npos);
    EXPECT_TRUE(output.find("Kirill") != std::string::npos);
    EXPECT_TRUE(output.find("Curators") != std::string::npos);
    EXPECT_TRUE(output.find("Masha") != std::string::npos);
    EXPECT_TRUE(output.find("Security") != std::string::npos);
    EXPECT_TRUE(output.find("Dima") != std::string::npos);
}