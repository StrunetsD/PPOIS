#ifndef ARTGALLERY_H
#define ARTGALLERY_H

#include "Painting.h"
#include "Artist.h"
#include "Client.h"
#include "Event.h"
#include "Workers.h"
#include "libraries.h"
#include "Review.h"

class ArtGallery final{
public:
  explicit ArtGallery(const string& name)
        : name_(name), workers_(new Workers()) {}
  string getName() const ;
  void addArtist(Artist* artist);
  void addPainting(Painting* painting);
  void addClient(Client* client);
  void showInfo() const ;
  void addEvent(Event* event);
  void addReview(Review* review);
  void showWorkers(Workers* workers) const;


private:
  string name_;
  vector<Painting*> paintings_;
  vector<Artist*> artists_;
  vector<Client*> clients_;
  Workers* workers_;
  vector<Event*> events_;
  vector<Review*> reviews_;
};
#endif //ARTGALLERY_H
