#ifndef PROJECTMANAGER_H
#define PROJECTMANAGER_H


#include "Employee.h"
class ProjectManager final : public Employee {
public:
    ProjectManager(const string& name, const int age, const double salary)
        : Employee(name, age, salary) {}
    void manageProject() const;
    void allocateResources() const;
    void monitorProgress() const;
};


#endif //PROJECTMANAGER_H
