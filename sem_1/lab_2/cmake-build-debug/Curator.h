#ifndef CURATOR_H
#define CURATOR_H
#include "libraries.h"
#include "Employee.h"
#include "Human.h"


class Curator final : public Human, public Employee {
public:
  Curator(const string name, const string arriveTime)
        : Human(name), Employee(arriveTime) {}
  void work() const override;

};



#endif //CURATOR_H
