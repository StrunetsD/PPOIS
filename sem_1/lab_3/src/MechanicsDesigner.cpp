#include "MechanicsDesigner.h"


void MechanicsDesigner::designMechanics() const {
    cout << getName() << " is designing game mechanics." << '\n';
}

void MechanicsDesigner::balanceGameMechanics() const {
    cout << getName() << " is balancing game mechanics." << '\n';
}

void MechanicsDesigner::createCombatSystem() const {
    cout << getName() << " is creating a combat system." << '\n';
}