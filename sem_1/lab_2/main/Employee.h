#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include "libraries.h"


class Employee {
public:
  explicit Employee(const string arriveTime) : arriveTime(arriveTime) {}
  virtual string getArriveTime() const {
    return arriveTime;
  }
  virtual void work() const = 0;
  virtual ~Employee() = default;
protected:
  string arriveTime;
};




#endif //EMPLOYEE_H
