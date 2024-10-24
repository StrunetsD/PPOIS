#include "Animator.h"


void Animator::animateCharacter() const {
    cout << getName() << " is animating character movements." << '\n';
}

void Animator::animateObjects() const {
    cout << getName() << " is animating objects." << '\n';
}