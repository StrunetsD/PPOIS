#ifndef CLIENT_H
#define CLIENT_H

#include "libraries.h"
#include "Painting.h"
#include "Human.h"
#include "Entity.h"

class Client final : public Human, public Entity{
public:
  Client(const string& name, const string& email, const string& password)
          : Human(name), email_(email), password_(password) {};
  string getEmail()const;
  string getPassword()const;
  void buyPainting(Painting& painting);
  void showInfo()const override;
private:
  string email_;
  string password_;
  bool checkPassword(string& inputPassword) const;
};



#endif //CLIENT_H
