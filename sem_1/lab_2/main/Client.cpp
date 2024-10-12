#include "includes.h"

string  Client::getEmail()const {
  return email_;
}
string  Client::getPassword()const {
  return password_;
}
void Client::showInfo()const {
    cout<<"Name: "<<getName()<<"\n";
    cout<<"Email: "<<getEmail()<<"\n";
    cout<<"Password: "<<getPassword()<<"\n";
}

bool Client::checkPassword(string& inputPassword) const  {
    return password_ == inputPassword;
}