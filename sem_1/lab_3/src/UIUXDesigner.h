#ifndef UIUXDESIGNER_H
#define UIUXDESIGNER_H


#include "Employee.h"
class UIUXDesigner final : public Employee {
public:
    UIUXDesigner(const std::string& name, const int age, const double salary)
        : Employee(name, age, salary) {}
    void designUI() const;
    void createUXFlow() const;
    void conductUserTesting() const;
};




#endif //UIUXDESIGNER_H
