#include "GameProject.h"

string GameProject::getTitle() const {
    return title_;
}

void GameProject::addTeamMember(Employee* employee) {
    team_.push_back(employee);
}

void GameProject::startDevelopment() const {
    cout << "Starting development of the game: " << title_ << '\n';
    projectManager_.manageProject();
    for (const auto& member : team_) {
        member->work();
    }
}

void GameProject::releaseGame() const {
    cout << "The game " << title_ << " is released!" <<'\n';
}