#include "ProjectManager.h"


void ProjectManager::manageProject() const {
    cout << getName() << " is managing the project." << '\n';
}

void ProjectManager::allocateResources() const {
    cout << getName() << " is allocating resources." << '\n';
}

void ProjectManager::monitorProgress() const {
    cout << getName() << " is monitoring the project progress." << '\n';
}