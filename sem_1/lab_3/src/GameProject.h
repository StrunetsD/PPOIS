#ifndef GAMEPROJECT_H
#define GAMEPROJECT_H

#include <utility>

#include "includes.h"

class GameProject {
public:
    GameProject(string  title, ProjectManager  manager)
        : title_(move(title)), projectManager_(move(manager)) {}
    string getTitle() const;
    void addTeamMember(Employee* employee);
    void startDevelopment() const;
    void releaseGame() const;
private:
    string title_;
    ProjectManager projectManager_;
    vector<Employee*> team_;
};



#endif //GAMEPROJECT_H
