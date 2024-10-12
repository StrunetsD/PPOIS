#ifndef SECURITY_H
#define SECURITY_H

#include "libraries.h"
#include "Employee.h"
#include "Human.h"


class Security final :public Employee, public Human {
public:
    Security(const string name, const string arriveTime)
        : Human(name), Employee(arriveTime) {}
    void work() const override;
};



#endif //SECURITY_H