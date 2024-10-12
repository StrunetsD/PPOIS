#ifndef HUMAN_H
#define HUMAN_H
#include "libraries.h"
class Human  {
protected:
    string name;

public:
    explicit Human(const string name) : name(name) {}

    string getName() const {
        return name;
    }
    virtual ~Human() = default;
};
#endif //HUMAN_H
