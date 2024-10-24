#ifndef AIENGINEER_H
#define AIENGINEER_H

#include "Employee.h"

class AIEngineer final : public Employee {
public:
    AIEngineer(const std::string& name, const int age, const double salary)
        : Employee(name, age, salary) {}
    void developAI() const;
    void setAIPatrolRoutes() const;
    void improveAI() const;
};


#endif //AIENGINEER_H
