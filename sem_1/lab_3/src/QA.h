#ifndef QA_H
#define QA_H


#include "Employee.h"
class QA final : public Employee {
public:
    QA(const string& name, const int age, const double salary)
        : Employee(name, age,salary) {}
    void testGame() const;
    void writeTestCases() const;
};



#endif //QA_H
