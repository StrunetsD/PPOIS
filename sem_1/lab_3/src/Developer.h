#ifndef DEVELOPER_H
#define DEVELOPER_H


#include "Employee.h"
class Developer final : public Employee {
public:
    Developer(const string name, const int age, const double salary)
        : Employee(name, age, salary) {}
    void developGame() const;
    void fixBugs() const;
};



#endif //DEVELOPER_H
