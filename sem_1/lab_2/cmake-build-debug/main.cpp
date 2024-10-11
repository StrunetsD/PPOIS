#include "ApplicationManager.h"
#include "gtest/gtest.h"
int main() {
    const ApplicationManager* applicationManager = new ApplicationManager();
    applicationManager->run();
     ::testing::InitGoogleTest();
     return RUN_ALL_TESTS();
}
