#ifndef EMPLOYEE_H
#define EMPLOYEE_H


#include "../src/Human.h"

class Employee : public Human {
public:
    explicit Employee(const string& name, const int age, const double salary ) : Human(name, age), salary_(salary){};
    void work() const override ;
    double getSalary() const ;
    void setSalary(double salary) ;

protected:
    double salary_;
};



#endif //EMPLOYEE_H
