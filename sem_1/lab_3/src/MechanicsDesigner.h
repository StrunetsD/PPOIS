#ifndef MECHANICSDESIGNER_H
#define MECHANICSDESIGNER_H


#include "Employee.h"
class MechanicsDesigner : public Employee {
public:
    MechanicsDesigner(const string& name, const int age, const double salary)
        : Employee(name, age, salary) {}
    void designMechanics() const;
    void balanceGameMechanics() const ;
    void createCombatSystem() const ;
};



#endif //MECHANICSDESIGNER_H
