#include "CharacterDesigner.h"


void CharacterDesigner::designCharacter(const string& characterName) const {
   cout << getName() << " is designing character: " << characterName << '\n';
}

void CharacterDesigner::chooseAppearance() const {
   cout << getName() << " is choosing character appearance." << '\n';
}

void CharacterDesigner::assignWeapon(const string& weapon) const  {
    cout << getName() << " assigned weapon: " << weapon << '\n';
}