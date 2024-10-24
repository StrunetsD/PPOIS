#include <gtest/gtest.h>
#include "src/ApplicationManager.h"
int main() {
    const ApplicationManager app;
     app.startDevelopment();
     ::testing::InitGoogleTest();
     return RUN_ALL_TESTS();
}
