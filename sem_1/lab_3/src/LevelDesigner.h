#ifndef LEVELDESIGNER_H
#define LEVELDESIGNER_H


#include "Employee.h"
class LevelDesigner final : public Employee {
public:
    LevelDesigner(const string& name, const int age, const double salary)
        : Employee(name, age, salary) {}
    void designLevel() const;
    void placeObjects() const;
};



#endif //LEVELDESIGNER_H
