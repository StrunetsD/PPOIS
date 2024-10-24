#ifndef CHARACTERDESIGNER_H
#define CHARACTERDESIGNER_H

#include "Employee.h"
class CharacterDesigner final : public Employee {
public:
    CharacterDesigner(const string& name, const int age, const double salary)
        : Employee(name, age, salary) {}

    void designCharacter(const string& characterName) const;

    void chooseAppearance() const ;

    void assignWeapon(const string& weapon) const  ;
};



#endif //CHARACTERDESIGNER_H
