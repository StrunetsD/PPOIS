#ifndef CATEGORY_H
#define CATEGORY_H


#include "libraries.h"


class Category {
public:
  explicit Category(const string& categoryName):categoryName_(categoryName){};
  string getCategoryName() const;
private:
  string categoryName_;
};
#endif //CATEGORY_H
