#include "Developer.h"


void Developer::developGame() const {
   cout << getName() << " is developing game code." << '\n';
}

void Developer::fixBugs() const {
    cout << getName() << " is fixing bugs." <<'\n';
}