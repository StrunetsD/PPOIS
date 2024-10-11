#include "Event.h"

int Event::lastId_ = 0;
int Event::getId()const {
  return id_;
}

string Event::getName()const {
  return name_;
}

string Event::getDate()const {
  return date_;
}
void Event::showInfo()const {
  cout<<"name: " <<getName()<<", "<<" date:  " << getDate()<<", "<<" id:  " << getId() << endl;
}