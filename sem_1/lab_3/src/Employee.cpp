#include "Employee.h"

double Employee::getSalary() const {
    return salary_;
}

void Employee::work() const {
   cout << getName() << " is working as an employee. Salary: " << getSalary() << '\n';
}
void Employee::setSalary(const double salary) {
    salary_ = salary;
}
