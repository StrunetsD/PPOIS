#ifndef ARTIST_H
#define ARTIST_H


#include "Employee.h"
class Artist final : public Employee {
public:
    Artist(const string& name, const int age, const double salary)
        : Employee(name, age, salary) {}
    void createGameAssets() const;
    void developConceptArt() const;
    void optimizeGraphics() const;
};


#endif //ARTIST_H
