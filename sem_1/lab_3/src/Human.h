#ifndef HUMAN_H
#define HUMAN_H

#include "libraries.h"


class Human {
public:
    Human(const string name, const int age) : name_(name), age_(age) {};
    string getName() const;
    int getAge() const;
    virtual void work() const = 0;
    virtual ~Human() = default;
protected:
    string name_;
    int age_;
};



#endif //HUMAN_H
