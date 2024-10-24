#ifndef CATEGORY_H
#define CATEGORY_H


#include "libraries.h"
class Category {
public:
    Category(const string name): name_(name) {};
    string getName() const { return name_;}

private:
    string name_;
};



#endif //CATEGORY_H
