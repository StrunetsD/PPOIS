#ifndef TOUR_H
#define TOUR_H

#include "libraries.h"

class Tour {
public:
    Tour(const string& name, const string& dateTime)
        : name_(name), dateTime_(dateTime) {}

    string getName() const { return name_; }
    string getDateTime() const { return dateTime_; }

private:
    string name_;
    string dateTime_;
};



#endif //TOUR_H
