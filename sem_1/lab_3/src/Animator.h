#ifndef ANIMATOR_H
#define ANIMATOR_H


#include "Employee.h"
class Animator final : public Employee {
public:
    Animator(const string& name, const int age, const double salary)
        : Employee(name, age, salary) {}
    void animateCharacter() const;
    void animateObjects() const;
};



#endif //ANIMATOR_H
