#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H

#include "Human.h"
#include "Employee.h"




class Administrator final : public Human, public Employee {
public:
    Administrator(const string name, const string arriveTime)
          : Human(name), Employee(arriveTime) {}
    void work() const override;

};



#endif //ADMINISTRATOR_H
