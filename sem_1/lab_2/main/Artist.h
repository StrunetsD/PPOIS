#ifndef ARTIST_H
#define ARTIST_H


#include "libraries.h"
#include "Human.h"
#include "Entity.h"


class Artist final : public Human, public Entity{

public:
  Artist(const string name, const string biography) : Human(name), biography_(biography) {};
  string getBiography()const;
  void showInfo() const override;
private:
  string biography_;
};


#endif //ARTIST_H
