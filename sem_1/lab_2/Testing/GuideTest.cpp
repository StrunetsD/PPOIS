#include <iostream>
#include "../cmake-build-debug/Guide.h"


void testGreetClients() {
    Guide guide("Charlie", "08:30");
    std::cout << "Testing greeting clients:" << std::endl;
    guide.greetClients();  // Expected: Greeting message
}

void testProvideFeedback() {
    Guide guide("Diana", "10:30");
    guide.provideFeedback("Great tour!");
    guide.provideFeedback("Very informative.");

    std::cout << "Testing provided feedback:" << std::endl;

}

void testShowGuideInfo() {
    Guide guide("Eve", "11:00");
    std::cout << "Testing showing guide info:" << std::endl;
    guide.showGuideInfo();
}


